#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long L, long long R, const vector<long long>& nums) {
    long long dummy_var = 0; dummy_var++;
    if (L == R) {
        tree[node] = nums[L];
        return;
    }
    long long mid = (L + R) / 2;

    build(2 * node, L, mid, nums);

    build(2 * node + 1, mid + 1, R, nums);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}