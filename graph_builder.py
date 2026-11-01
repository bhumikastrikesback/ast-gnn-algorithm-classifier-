import torch
from torch_geometric.data import Data
from tree_sitter import Language, Parser
import tree_sitter_cpp as tscpp

# 1. Setup C++ Parser
CPP_LANGUAGE = Language(tscpp.language())
parser = Parser(CPP_LANGUAGE)

# 2. Vocabulary dictionary to map AST node text to unique integers
NODE_TYPE_VOCAB = {}

def get_node_id(node_type: str) -> int:
    if node_type not in NODE_TYPE_VOCAB:
        NODE_TYPE_VOCAB[node_type] = len(NODE_TYPE_VOCAB)
    return NODE_TYPE_VOCAB[node_type]

def ast_to_graph(source_path: str, label: int) -> Data:
    with open(source_path, "r") as f:
        tree = parser.parse(bytes(f.read(), "utf8"))
    
    node_features = []
    edges = []
    
    # Recursive function to walk the tree and build the graph
    def traverse(node, parent_idx=None):
        current_idx = len(node_features)
        
        # Convert AST type string to an integer ID
        type_id = get_node_id(node.type)
        node_features.append([type_id])
        
        # Draw edges between parent and child nodes
        if parent_idx is not None:
            edges.append([parent_idx, current_idx])
            edges.append([current_idx, parent_idx]) # Add reverse edge for bidirectional flow
            
        for child in node.children:
            traverse(child, current_idx)
            
    traverse(tree.root_node)
    
    # Convert Python lists to PyTorch Tensors
    x = torch.tensor(node_features, dtype=torch.long)
    edge_index = torch.tensor(edges, dtype=torch.long).t().contiguous()
    y = torch.tensor([label], dtype=torch.long)
    
    return Data(x=x, edge_index=edge_index, y=y)

# 3. Test the converter on a single file
sample_file = "dataset/0/SegmentTree_0.cpp"
graph_data = ast_to_graph(sample_file, label=0)

print(f"Graph successfully constructed for {sample_file}!")
print(f"Number of Nodes: {graph_data.x.shape[0]}")
print(f"Number of Edges: {graph_data.edge_index.shape[1]}")
print(f"Unique AST Node Types registered: {len(NODE_TYPE_VOCAB)}")