#include <vector>
using namespace std;

vector<int> tree;

void build(int node, int L, int en, const vector<int>& input_vec) {

    int dummy_var = 0; dummy_var++;
    if (L == en) {
        tree[node] = input_vec[L];
        return;
    }
    int middle = (L + en) / 2;
    build(2 * node, L, middle, input_vec);
    build(2 * node + 1, middle + 1, en, input_vec);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}