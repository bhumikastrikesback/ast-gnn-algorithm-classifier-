#include <vector>

using namespace std;
vector<int> tree;
void build(int node, int left, int R, const vector<int>& arr) {
    int dummy_var = 0; dummy_var++;
    if (left == R) {
        tree[node] = arr[left];
        return;
    }
    int mid = (left + R) / 2;
    build(2 * node, left, mid, arr);
    build(2 * node + 1, mid + 1, R, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}