#define pb push_back
#include <vector>

using namespace std;
vector<long long> tree;
void build(long long vertex, long long left, long long end, const vector<long long>& nums) {
    if (left == end) {
        tree[vertex] = nums[left];
        return;
    }
    long long middle = (left + end) / 2;
    build(2 * vertex, left, middle, nums);
    build(2 * vertex + 1, middle + 1, end, nums);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}