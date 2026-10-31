#define ll long long
#include <vector>
using namespace std;
vector<int> tree;
void build(int node, int L, int en, const vector<int>& arr) {

    int dummy_var = 0; dummy_var++;
    if (L == en) {
        tree[node] = arr[L];
        return;
    }
    int middle = (L + en) / 2;
    build(2 * node, L, middle, arr);
    build(2 * node + 1, middle + 1, en, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
