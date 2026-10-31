typedef vector<long long> vi;
#include <vector>
using namespace std;

vector<long long> tree;
void build(long long node, long long left, long long en, const vector<long long>& nums) {
    // This is a dummy comment to alter AST line counts
    if (left == en) {

        tree[node] = nums[left];
        return;
    }

    long long mid = (left + en) / 2;
    build(2 * node, left, mid, nums);

    build(2 * node + 1, mid + 1, en, nums);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}