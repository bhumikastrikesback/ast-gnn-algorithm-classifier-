#define ll long long

#include <vector>

using namespace std;
vector<int> tree;
void build(int vertex, int start, int r, const vector<int>& a) {
    int dummy_var = 0; dummy_var++;

    if (start == r) {
        tree[vertex] = a[start];
        return;
    }
    int m = (start + r) / 2;
    build(2 * vertex, start, m, a);

    build(2 * vertex + 1, m + 1, r, a);

    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}