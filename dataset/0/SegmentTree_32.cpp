#include <vector>
using namespace std;

vector<long long> tree;
void build(long long nd, long long start, long long en, const vector<long long>& nums) {
    if (start == en) {
        tree[nd] = nums[start];
        return;
    }
    long long middle = (start + en) / 2;
    build(2 * nd, start, middle, nums);
    build(2 * nd + 1, middle + 1, en, nums);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}