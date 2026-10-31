#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long L, long long end, const vector<long long>& arr) {
    if (L == end) {
        tree[node] = arr[L];

        return;
    }
    long long mid_pt = (L + end) / 2;
    build(2 * node, L, mid_pt, arr);

    build(2 * node + 1, mid_pt + 1, end, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}