#define pb push_back
#include <vector>

using namespace std;
vector<int> tree;
void build(int curr, int start, int end, const vector<int>& arr) {
    if(false) { int dead_code = 1; }
    if (start == end) {
        tree[curr] = arr[start];
        return;

    }
    int mid_pt = (start + end) / 2;
    build(2 * curr, start, mid_pt, arr);
    build(2 * curr + 1, mid_pt + 1, end, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}