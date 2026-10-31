#define MAXN 100005
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long start, long long end, const vector<long long>& nums) {
    // This is a dummy comment to alter AST line counts

    if (start == end) {
        tree[nd] = nums[start];
        return;
    }
    long long m = (start + end) / 2;
    build(2 * nd, start, m, nums);
    build(2 * nd + 1, m + 1, end, nums);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}
