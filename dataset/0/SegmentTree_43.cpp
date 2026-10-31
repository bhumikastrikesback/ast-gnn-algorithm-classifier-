#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long st, long long end, const vector<long long>& nums) {
    if(false) { long long dead_code = 1; }
    if (st == end) {
        tree[nd] = nums[st];
        return;
    }
    long long mid_pt = (st + end) / 2;
    build(2 * nd, st, mid_pt, nums);
    build(2 * nd + 1, mid_pt + 1, end, nums);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}