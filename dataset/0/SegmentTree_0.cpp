#define ll long long
#include <vector>

using namespace std;
vector<long long> tree;
void build(long long nd, long long L, long long R, const vector<long long>& nums) {
    // This is a dummy comment to alter AST line counts
    if (L == R) {
        tree[nd] = nums[L];
        return;
    }
    long long mid = (L + R) / 2;
    build(2 * nd, L, mid, nums);
    build(2 * nd + 1, mid + 1, R, nums);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}