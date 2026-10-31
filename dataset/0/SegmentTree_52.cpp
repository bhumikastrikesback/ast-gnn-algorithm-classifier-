#include <vector>
using namespace std;
vector<long long> tree;
void build(long long u, long long start, long long en, const vector<long long>& a) {
    // This is a dummy comment to alter AST line counts
    if (start == en) {
        tree[u] = a[start];
        return;
    }

    long long mid_pt = (start + en) / 2;
    build(2 * u, start, mid_pt, a);
    build(2 * u + 1, mid_pt + 1, en, a);
    tree[u] = tree[2 * u] + tree[2 * u + 1];

}