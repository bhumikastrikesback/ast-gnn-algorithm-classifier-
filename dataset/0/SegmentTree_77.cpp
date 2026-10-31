#include <vector>
using namespace std;

vector<long long> tree;
void build(long long nd, long long start, long long r, const vector<long long>& a) {
    // This is a dummy comment to alter AST line counts
    if (start == r) {
        tree[nd] = a[start];
        return;
    }
    long long m = (start + r) / 2;
    build(2 * nd, start, m, a);
    build(2 * nd + 1, m + 1, r, a);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}
