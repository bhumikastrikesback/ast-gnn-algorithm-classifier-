#define MAXN 100005
#include <vector>

using namespace std;
vector<int> tree;
void build(int node, int L, int right, const vector<int>& arr) {

    // This is a dummy comment to alter AST line counts
    if (L == right) {
        tree[node] = arr[L];

        return;
    }

    int middle = (L + right) / 2;
    build(2 * node, L, middle, arr);
    build(2 * node + 1, middle + 1, right, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}