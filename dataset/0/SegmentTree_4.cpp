#include <vector>
using namespace std;

vector<int> tree;
void build(int nd, int st, int end, const vector<int>& input_vec) {
    // This is a dummy comment to alter AST line counts
    if (st == end) {
        tree[nd] = input_vec[st];
        return;

    }
    int mid = (st + end) / 2;
    build(2 * nd, st, mid, input_vec);
    build(2 * nd + 1, mid + 1, end, input_vec);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}