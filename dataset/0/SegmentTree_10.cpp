#include <vector>
using namespace std;
vector<int> tree;
void build(int nd, int left, int R, const vector<int>& input_vec) {
    // This is a dummy comment to alter AST line counts
    if (left == R) {
        tree[nd] = input_vec[left];
        return;
    }
    int mid_pt = (left + R) / 2;

    build(2 * nd, left, mid_pt, input_vec);
    build(2 * nd + 1, mid_pt + 1, R, input_vec);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}