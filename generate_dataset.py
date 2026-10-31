import os
import random
import re

# Configuration
NUM_VARIATIONS = 100
CLASSES = ['SegmentTree', 'FenwickTree', 'DFS']
SEED_DIR = '.'
OUTPUT_DIR = 'dataset'

# Mutation Dictionaries
VAR_SWAPS = {
    'node': ['u', 'curr', 'nd', 'vertex'],
    'start': ['l', 'left', 'st', 'L'],
    'end': ['r', 'right', 'en', 'R'],
    'mid': ['m', 'middle', 'mid_pt'],
    'idx': ['i', 'pos', 'index', 'p'],
    'val': ['v', 'delta', 'value', 'x'],
    'neighbor': ['v', 'nxt', 'adj_node'],
    'sum': ['res', 'total', 'ans'],
    'arr': ['a', 'nums', 'input_vec']
}

MACROS = [
    "#define ll long long\n",
    "#define pb push_back\n",
    "#define MAXN 100005\n",
    "typedef vector<int> vi;\n"
]

DUMMY_CODE = [
    "    int dummy_var = 0; dummy_var++;\n",
    "    // This is a dummy comment to alter AST line counts\n",
    "    if(false) { int dead_code = 1; }\n"
]

def mutate_code(source_code):
    mutated = source_code
    
    # 1. Variable Renaming
    for original, replacements in VAR_SWAPS.items():
        if random.random() > 0.3: # 70% chance to swap this variable
            new_var = random.choice(replacements)
            # Regex ensures we only replace whole words, not partial matches
            mutated = re.sub(rf'\b{original}\b', new_var, mutated)

    # 2. Inject Macros at the top
    if random.random() > 0.5:
        mutated = random.choice(MACROS) + mutated

    # 3. Inject Dead Code/Comments inside function bodies (after open brackets)
    if random.random() > 0.4:
        dummy_injection = random.choice(DUMMY_CODE)
        mutated = mutated.replace('{\n', '{\n' + dummy_injection, 1)

    # 4. Data Type Swapping (int -> long long)
    if random.random() > 0.5:
        mutated = re.sub(r'\bint\b', 'long long', mutated)

    # 5. Whitespace Noise (randomly add blank lines)
    lines = mutated.split('\n')
    noisy_lines = []
    for line in lines:
        noisy_lines.append(line)
        if random.random() > 0.8:
            noisy_lines.append("")
            
    return '\n'.join(noisy_lines)

def build_dataset():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    
    for class_idx, class_name in enumerate(CLASSES):
        seed_path = os.path.join(SEED_DIR, f"{class_name}.cpp")
        class_out_dir = os.path.join(OUTPUT_DIR, str(class_idx))
        os.makedirs(class_out_dir, exist_ok=True)
        
        with open(seed_path, 'r') as f:
            seed_code = f.read()
            
        print(f"Generating {NUM_VARIATIONS} variations for {class_name}...")
        
        for i in range(NUM_VARIATIONS):
            mutated_code = mutate_code(seed_code)
            out_file = os.path.join(class_out_dir, f"{class_name}_{i}.cpp")
            
            with open(out_file, 'w') as f:
                f.write(mutated_code)

if __name__ == "__main__":
    build_dataset()
    print("Dataset generation complete!")