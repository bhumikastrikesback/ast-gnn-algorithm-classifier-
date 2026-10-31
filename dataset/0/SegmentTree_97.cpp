#define MAXN 100005
#include <vector>

using namespace std;

vector<int> tree;
void build(int u, int L, int right, const vector<int>& arr) {
    // This is a dummy comment to alter AST line counts
    if (L == right) {
        tree[u] = arr[L];
        return;
    }
    int mid_pt = (L + right) / 2;
    build(2 * u, L, mid_pt, arr);
    build(2 * u + 1, mid_pt + 1, right, arr);

    tree[u] = tree[2 * u] + tree[2 * u + 1];
}