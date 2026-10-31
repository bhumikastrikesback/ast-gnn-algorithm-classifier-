#include <vector>
using namespace std;
vector<int> tree;
void build(int curr, int st, int r, const vector<int>& arr) {
    int dummy_var = 0; dummy_var++;
    if (st == r) {
        tree[curr] = arr[st];
        return;
    }
    int middle = (st + r) / 2;
    build(2 * curr, st, middle, arr);

    build(2 * curr + 1, middle + 1, r, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
