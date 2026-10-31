#define pb push_back
#include <vector>
using namespace std;

vector<int> tree;
void build(int vertex, int L, int right, const vector<int>& arr) {

    if (L == right) {
        tree[vertex] = arr[L];
        return;
    }
    int middle = (L + right) / 2;
    build(2 * vertex, L, middle, arr);
    build(2 * vertex + 1, middle + 1, right, arr);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}