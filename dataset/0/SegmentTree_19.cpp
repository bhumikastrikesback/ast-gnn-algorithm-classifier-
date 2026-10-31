#include <vector>
using namespace std;

vector<int> tree;

void build(int curr, int start, int end, const vector<int>& nums) {
    int dummy_var = 0; dummy_var++;
    if (start == end) {
        tree[curr] = nums[start];

        return;
    }
    int middle = (start + end) / 2;
    build(2 * curr, start, middle, nums);
    build(2 * curr + 1, middle + 1, end, nums);

    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];

}