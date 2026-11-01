import os
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch_geometric.data import Data
from torch_geometric.loader import DataLoader
from torch_geometric.nn import GCNConv, global_mean_pool
from tree_sitter import Language, Parser
import tree_sitter_cpp as tscpp
from torch.utils.data import random_split

# 1. Parser and Vocabulary Setup
CPP_LANGUAGE = Language(tscpp.language())
parser = Parser(CPP_LANGUAGE)
NODE_TYPE_VOCAB = {}

def get_node_id(node_type: str) -> int:
    if node_type not in NODE_TYPE_VOCAB:
        NODE_TYPE_VOCAB[node_type] = len(NODE_TYPE_VOCAB)
    return NODE_TYPE_VOCAB[node_type]

def ast_to_graph(source_path: str, label: int) -> Data:
    with open(source_path, "r") as f:
        tree = parser.parse(bytes(f.read(), "utf8"))
    
    node_features, edges = [], []
    def traverse(node, parent_idx=None):
        current_idx = len(node_features)
        node_features.append([get_node_id(node.type)])
        if parent_idx is not None:
            edges.extend([[parent_idx, current_idx], [current_idx, parent_idx]])
        for child in node.children:
            traverse(child, current_idx)
            
    traverse(tree.root_node)
    x = torch.tensor(node_features, dtype=torch.long)
    edge_index = torch.tensor(edges, dtype=torch.long).t().contiguous() if edges else torch.empty((2, 0), dtype=torch.long)
    return Data(x=x, edge_index=edge_index, y=torch.tensor([label], dtype=torch.long))

# 2. Dataset Loader
def load_dataset(base_dir="dataset"):
    print("Extracting ASTs and building graphs...")
    graphs = []
    for label in [0, 1, 2]:
        folder = os.path.join(base_dir, str(label))
        for file in os.listdir(folder):
            if file.endswith(".cpp"):
                path = os.path.join(folder, file)
                graphs.append(ast_to_graph(path, label))
    return graphs

# 3. Graph Neural Network Architecture
class ASTGraphClassifier(nn.Module):
    def __init__(self, vocab_size, embed_dim=32, hidden_dim=64, num_classes=3):
        super().__init__()
        # Maps integer node IDs to dense vectors
        self.embedding = nn.Embedding(vocab_size, embed_dim)
        
        # Message Passing Layers
        self.conv1 = GCNConv(embed_dim, hidden_dim)
        self.conv2 = GCNConv(hidden_dim, hidden_dim)
        
        # Final Classification Layers
        self.fc1 = nn.Linear(hidden_dim, hidden_dim // 2)
        self.fc2 = nn.Linear(hidden_dim // 2, num_classes)

    def forward(self, x, edge_index, batch):
        x = self.embedding(x.squeeze(-1))
        
        # Graph convolutions
        x = F.relu(self.conv1(x, edge_index))
        x = F.relu(self.conv2(x, edge_index))
        
        # Global pooling collapses the varying-sized trees into a single vector
        x = global_mean_pool(x, batch)
        
        x = F.relu(self.fc1(x))
        return self.fc2(x)

# 4. Training Loop
if __name__ == "__main__":
    dataset = load_dataset()
    
    # 1. Create an 80/20 Train/Test Split
    train_size = int(0.8 * len(dataset))
    test_size = len(dataset) - train_size
    train_dataset, test_dataset = random_split(dataset, [train_size, test_size])
    
    train_loader = DataLoader(train_dataset, batch_size=16, shuffle=True)
    test_loader = DataLoader(test_dataset, batch_size=16, shuffle=False)
    
    vocab_size = len(NODE_TYPE_VOCAB)
    print(f"Total unique AST nodes found: {vocab_size}")
    
    model = ASTGraphClassifier(vocab_size=vocab_size)
    
    # Adding weight decay (L2 Regularization) to prevent overfitting
    optimizer = torch.optim.Adam(model.parameters(), lr=0.005, weight_decay=1e-4)
    criterion = nn.CrossEntropyLoss()

    print("Starting Training with Validation...")
    for epoch in range(1, 11):
        # Training Phase
        model.train()
        total_loss = 0
        for data in train_loader:
            optimizer.zero_grad()
            out = model(data.x, data.edge_index, data.batch)
            loss = criterion(out, data.y)
            loss.backward()
            optimizer.step()
            total_loss += loss.item()
            
        # Testing/Validation Phase (On Unseen Data)
        model.eval()
        correct = 0
        with torch.no_grad():
            for data in test_loader:
                out = model(data.x, data.edge_index, data.batch)
                pred = out.argmax(dim=1)
                correct += int((pred == data.y).sum())
        
        test_acc = correct / len(test_dataset)
        train_loss = total_loss / len(train_loader)
        print(f"Epoch {epoch:02d} | Train Loss: {train_loss:.4f} | Test Acc: {test_acc:.4f}")