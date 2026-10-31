#include <vector>
using namespace std;

vector<long long> tree;
void build(long long curr, long long start, long long r, const vector<long long>& arr) {
    if(false) { long long dead_code = 1; }
    if (start == r) {
        tree[curr] = arr[start];

        return;

    }
    long long mid_pt = (start + r) / 2;

    build(2 * curr, start, mid_pt, arr);
    build(2 * curr + 1, mid_pt + 1, r, arr);

    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}