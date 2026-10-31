#include <vector>
using namespace std;
vector<long long> tree;

void build(long long node, long long start, long long R, const vector<long long>& nums) {
    // This is a dummy comment to alter AST line counts
    if (start == R) {

        tree[node] = nums[start];
        return;

    }
    long long mid = (start + R) / 2;
    build(2 * node, start, mid, nums);
    build(2 * node + 1, mid + 1, R, nums);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}