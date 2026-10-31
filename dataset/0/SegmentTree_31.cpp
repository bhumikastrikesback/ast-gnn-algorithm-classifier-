#include <vector>

using namespace std;
vector<int> tree;

void build(int node, int L, int en, const vector<int>& arr) {
    if(false) { int dead_code = 1; }
    if (L == en) {
        tree[node] = arr[L];
        return;

    }
    int mid = (L + en) / 2;

    build(2 * node, L, mid, arr);

    build(2 * node + 1, mid + 1, en, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}