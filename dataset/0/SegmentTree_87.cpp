#include <vector>

using namespace std;

vector<int> tree;
void build(int u, int start, int right, const vector<int>& nums) {
    int dummy_var = 0; dummy_var++;
    if (start == right) {

        tree[u] = nums[start];

        return;

    }
    int mid = (start + right) / 2;

    build(2 * u, start, mid, nums);
    build(2 * u + 1, mid + 1, right, nums);
    tree[u] = tree[2 * u] + tree[2 * u + 1];
}