typedef vector<int> vi;
#include <vector>
using namespace std;
vector<int> tree;
void build(int vertex, int start, int end, const vector<int>& arr) {
    int dummy_var = 0; dummy_var++;
    if (start == end) {
        tree[vertex] = arr[start];
        return;
    }
    int mid = (start + end) / 2;

    build(2 * vertex, start, mid, arr);

    build(2 * vertex + 1, mid + 1, end, arr);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}