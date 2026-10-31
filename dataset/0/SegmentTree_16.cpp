#define pb push_back
#include <vector>
using namespace std;
vector<int> tree;
void build(int vertex, int start, int en, const vector<int>& nums) {
    // This is a dummy comment to alter AST line counts

    if (start == en) {
        tree[vertex] = nums[start];
        return;

    }
    int middle = (start + en) / 2;

    build(2 * vertex, start, middle, nums);
    build(2 * vertex + 1, middle + 1, en, nums);

    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];

}