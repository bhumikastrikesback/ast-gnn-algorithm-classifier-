#include <vector>
using namespace std;
vector<int> tree;
void build(int u, int left, int right, const vector<int>& a) {
    if (left == right) {
        tree[u] = a[left];
        return;
    }
    int m = (left + right) / 2;
    build(2 * u, left, m, a);
    build(2 * u + 1, m + 1, right, a);
    tree[u] = tree[2 * u] + tree[2 * u + 1];

}