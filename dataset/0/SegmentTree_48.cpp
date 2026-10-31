#define ll long long

#include <vector>

using namespace std;
vector<int> tree;
void build(int vertex, int start, int right, const vector<int>& a) {
    int dummy_var = 0; dummy_var++;

    if (start == right) {
        tree[vertex] = a[start];
        return;
    }
    int middle = (start + right) / 2;

    build(2 * vertex, start, middle, a);
    build(2 * vertex + 1, middle + 1, right, a);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}