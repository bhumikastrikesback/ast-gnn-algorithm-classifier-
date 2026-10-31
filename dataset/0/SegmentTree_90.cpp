#define ll long long

#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long st, long long en, const vector<long long>& arr) {

    if (st == en) {
        tree[node] = arr[st];
        return;
    }
    long long mid = (st + en) / 2;
    build(2 * node, st, mid, arr);
    build(2 * node + 1, mid + 1, en, arr);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}