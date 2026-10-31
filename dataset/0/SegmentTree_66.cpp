#include <vector>
using namespace std;
vector<long long> tree;

void build(long long node, long long start, long long end, const vector<long long>& nums) {
    if (start == end) {
        tree[node] = nums[start];

        return;
    }
    long long mid = (start + end) / 2;
    build(2 * node, start, mid, nums);
    build(2 * node + 1, mid + 1, end, nums);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}