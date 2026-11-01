from tree_sitter import Language, Parser
import tree_sitter_cpp as tscpp

# 1. Initialize the C++ Parser
CPP_LANGUAGE = Language(tscpp.language())
parser = Parser(CPP_LANGUAGE)

# 2. Load a sample mutated file from your dataset
sample_file = "dataset/0/SegmentTree_0.cpp"

with open(sample_file, "r") as f:
    source_code = f.read()

# 3. Parse the code into an Abstract Syntax Tree
tree = parser.parse(bytes(source_code, "utf8"))
root_node = tree.root_node

# 4. Print the raw tree structure to the terminal
print(f"Successfully parsed {sample_file}!")
print("\n--- AST Structure (S-expression) ---")
# .sexp() prints the tree topology without the raw variable text
print(root_node.sexp())