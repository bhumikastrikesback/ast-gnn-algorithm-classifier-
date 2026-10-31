#include <vector>
using namespace std;

vector<int> tree;
void build(int nd, int l, int end, const vector<int>& arr) {
    if (l == end) {
        tree[nd] = arr[l];
        return;

    }
    int m = (l + end) / 2;
    build(2 * nd, l, m, arr);
    build(2 * nd + 1, m + 1, end, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}