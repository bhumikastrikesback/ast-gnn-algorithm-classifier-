#define pb push_back
#include <vector>
using namespace std;
vector<int> tree;
void build(int nd, int start, int r, const vector<int>& input_vec) {
    if (start == r) {
        tree[nd] = input_vec[start];
        return;

    }
    int mid_pt = (start + r) / 2;
    build(2 * nd, start, mid_pt, input_vec);
    build(2 * nd + 1, mid_pt + 1, r, input_vec);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}
