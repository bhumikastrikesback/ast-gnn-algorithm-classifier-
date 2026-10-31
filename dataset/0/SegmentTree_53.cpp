#include <vector>

using namespace std;
vector<int> tree;
void build(int u, int st, int R, const vector<int>& nums) {
    if (st == R) {
        tree[u] = nums[st];
        return;
    }
    int m = (st + R) / 2;

    build(2 * u, st, m, nums);
    build(2 * u + 1, m + 1, R, nums);
    tree[u] = tree[2 * u] + tree[2 * u + 1];
}
