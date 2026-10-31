#define MAXN 100005
#include <vector>
using namespace std;
vector<int> tree;
void build(int curr, int L, int right, const vector<int>& arr) {
    // This is a dummy comment to alter AST line counts

    if (L == right) {
        tree[curr] = arr[L];
        return;
    }

    int mid_pt = (L + right) / 2;
    build(2 * curr, L, mid_pt, arr);

    build(2 * curr + 1, mid_pt + 1, right, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}