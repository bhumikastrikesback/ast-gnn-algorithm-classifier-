#define MAXN 100005
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long curr, long long start, long long end, const vector<long long>& arr) {

    if (start == end) {
        tree[curr] = arr[start];

        return;

    }
    long long mid_pt = (start + end) / 2;
    build(2 * curr, start, mid_pt, arr);
    build(2 * curr + 1, mid_pt + 1, end, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}