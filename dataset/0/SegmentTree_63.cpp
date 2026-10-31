typedef vector<int> vi;
#include <vector>
using namespace std;

vector<int> tree;
void build(int nd, int st, int r, const vector<int>& a) {
    if (st == r) {
        tree[nd] = a[st];
        return;

    }
    int mid_pt = (st + r) / 2;
    build(2 * nd, st, mid_pt, a);
    build(2 * nd + 1, mid_pt + 1, r, a);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}