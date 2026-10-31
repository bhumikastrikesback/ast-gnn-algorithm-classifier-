#include <vector>
using namespace std;
vector<long long> tree;

void build(long long nd, long long l, long long r, const vector<long long>& arr) {
    // This is a dummy comment to alter AST line counts
    if (l == r) {

        tree[nd] = arr[l];
        return;
    }

    long long m = (l + r) / 2;
    build(2 * nd, l, m, arr);
    build(2 * nd + 1, m + 1, r, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}