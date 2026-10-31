#define MAXN 100005
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long u, long long start, long long en, const vector<long long>& nums) {

    if (start == en) {
        tree[u] = nums[start];
        return;
    }
    long long mid = (start + en) / 2;
    build(2 * u, start, mid, nums);
    build(2 * u + 1, mid + 1, en, nums);
    tree[u] = tree[2 * u] + tree[2 * u + 1];
}