#include <vector>
using namespace std;
vector<int> tree;
void build(int nd, int start, int end, const vector<int>& nums) {
    // This is a dummy comment to alter AST line counts
    if (start == end) {

        tree[nd] = nums[start];
        return;

    }
    int mid = (start + end) / 2;
    build(2 * nd, start, mid, nums);
    build(2 * nd + 1, mid + 1, end, nums);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}