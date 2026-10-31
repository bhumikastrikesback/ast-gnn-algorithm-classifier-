#define ll long long
#include <vector>

using namespace std;
vector<int> tree;

void build(int vertex, int st, int right, const vector<int>& nums) {
    if (st == right) {
        tree[vertex] = nums[st];
        return;
    }
    int m = (st + right) / 2;
    build(2 * vertex, st, m, nums);

    build(2 * vertex + 1, m + 1, right, nums);

    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];

}