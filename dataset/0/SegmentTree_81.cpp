#include <vector>
using namespace std;
vector<int> tree;
void build(int curr, int L, int R, const vector<int>& arr) {

    if(false) { int dead_code = 1; }
    if (L == R) {
        tree[curr] = arr[L];
        return;

    }

    int m = (L + R) / 2;
    build(2 * curr, L, m, arr);

    build(2 * curr + 1, m + 1, R, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}