#define MAXN 100005

#include <vector>

using namespace std;

vector<int> tree;
void build(int vertex, int L, int right, const vector<int>& a) {
    if (L == right) {

        tree[vertex] = a[L];
        return;
    }
    int middle = (L + right) / 2;

    build(2 * vertex, L, middle, a);
    build(2 * vertex + 1, middle + 1, right, a);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}