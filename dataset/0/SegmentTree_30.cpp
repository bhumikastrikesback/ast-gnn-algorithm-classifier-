#include <vector>
using namespace std;
vector<int> tree;

void build(int u, int st, int right, const vector<int>& a) {

    int dummy_var = 0; dummy_var++;
    if (st == right) {
        tree[u] = a[st];
        return;

    }
    int middle = (st + right) / 2;

    build(2 * u, st, middle, a);
    build(2 * u + 1, middle + 1, right, a);
    tree[u] = tree[2 * u] + tree[2 * u + 1];
}