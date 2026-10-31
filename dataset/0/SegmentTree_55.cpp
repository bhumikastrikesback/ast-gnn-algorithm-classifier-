#include <vector>
using namespace std;
vector<int> tree;
void build(int node, int st, int r, const vector<int>& input_vec) {

    if (st == r) {

        tree[node] = input_vec[st];
        return;
    }
    int middle = (st + r) / 2;

    build(2 * node, st, middle, input_vec);
    build(2 * node + 1, middle + 1, r, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
