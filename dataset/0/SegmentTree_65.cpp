typedef vector<long long> vi;

#include <vector>
using namespace std;
vector<long long> tree;
void build(long long u, long long left, long long end, const vector<long long>& nums) {
    if(false) { long long dead_code = 1; }

    if (left == end) {
        tree[u] = nums[left];
        return;

    }
    long long m = (left + end) / 2;
    build(2 * u, left, m, nums);
    build(2 * u + 1, m + 1, end, nums);
    tree[u] = tree[2 * u] + tree[2 * u + 1];

}