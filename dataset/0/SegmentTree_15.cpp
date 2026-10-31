#include <vector>
using namespace std;
vector<int> tree;
void build(int curr, int left, int end, const vector<int>& nums) {
    // This is a dummy comment to alter AST line counts

    if (left == end) {
        tree[curr] = nums[left];
        return;

    }

    int mid = (left + end) / 2;
    build(2 * curr, left, mid, nums);
    build(2 * curr + 1, mid + 1, end, nums);

    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
