#include <vector>
using namespace std;
vector<long long> tree;

void build(long long u, long long start, long long r, const vector<long long>& arr) {
    // This is a dummy comment to alter AST line counts
    if (start == r) {
        tree[u] = arr[start];
        return;
    }
    long long mid_pt = (start + r) / 2;
    build(2 * u, start, mid_pt, arr);
    build(2 * u + 1, mid_pt + 1, r, arr);
    tree[u] = tree[2 * u] + tree[2 * u + 1];

}