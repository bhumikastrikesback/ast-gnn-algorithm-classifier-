#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long L, long long right, const vector<long long>& nums) {
    if(false) { long long dead_code = 1; }
    if (L == right) {
        tree[nd] = nums[L];
        return;
    }
    long long mid_pt = (L + right) / 2;
    build(2 * nd, L, mid_pt, nums);
    build(2 * nd + 1, mid_pt + 1, right, nums);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}