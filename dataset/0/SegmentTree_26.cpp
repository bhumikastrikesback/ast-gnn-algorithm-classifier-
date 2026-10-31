typedef vector<long long> vi;

#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long left, long long end, const vector<long long>& nums) {
    if (left == end) {

        tree[node] = nums[left];
        return;
    }

    long long mid_pt = (left + end) / 2;
    build(2 * node, left, mid_pt, nums);
    build(2 * node + 1, mid_pt + 1, end, nums);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}