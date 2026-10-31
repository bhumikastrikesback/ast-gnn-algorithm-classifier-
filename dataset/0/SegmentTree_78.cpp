#include <vector>

using namespace std;

vector<int> tree;
void build(int nd, int L, int R, const vector<int>& nums) {
    int dummy_var = 0; dummy_var++;
    if (L == R) {
        tree[nd] = nums[L];
        return;
    }
    int middle = (L + R) / 2;
    build(2 * nd, L, middle, nums);
    build(2 * nd + 1, middle + 1, R, nums);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}