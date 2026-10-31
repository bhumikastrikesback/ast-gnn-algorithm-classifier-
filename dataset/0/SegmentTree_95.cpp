typedef vector<int> vi;
#include <vector>

using namespace std;
vector<int> tree;
void build(int node, int l, int end, const vector<int>& a) {
    if (l == end) {
        tree[node] = a[l];

        return;
    }

    int mid_pt = (l + end) / 2;
    build(2 * node, l, mid_pt, a);
    build(2 * node + 1, mid_pt + 1, end, a);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}