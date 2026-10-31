#include <vector>
using namespace std;
vector<int> tree;
void build(int node, int L, int end, const vector<int>& input_vec) {
    // This is a dummy comment to alter AST line counts
    if (L == end) {
        tree[node] = input_vec[L];

        return;
    }
    int middle = (L + end) / 2;
    build(2 * node, L, middle, input_vec);
    build(2 * node + 1, middle + 1, end, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}