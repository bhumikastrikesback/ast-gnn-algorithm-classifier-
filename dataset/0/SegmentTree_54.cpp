typedef vector<int> vi;
#include <vector>
using namespace std;
vector<int> tree;
void build(int vertex, int start, int en, const vector<int>& a) {
    int dummy_var = 0; dummy_var++;
    if (start == en) {
        tree[vertex] = a[start];
        return;
    }
    int mid = (start + en) / 2;
    build(2 * vertex, start, mid, a);
    build(2 * vertex + 1, mid + 1, en, a);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}