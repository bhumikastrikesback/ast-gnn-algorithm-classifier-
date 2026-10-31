#include <vector>

using namespace std;
vector<long long> tree;

void build(long long curr, long long l, long long R, const vector<long long>& a) {
    if (l == R) {
        tree[curr] = a[l];
        return;
    }

    long long mid = (l + R) / 2;
    build(2 * curr, l, mid, a);
    build(2 * curr + 1, mid + 1, R, a);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}