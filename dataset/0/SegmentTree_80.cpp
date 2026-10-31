#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long l, long long right, const vector<long long>& a) {

    long long dummy_var = 0; dummy_var++;

    if (l == right) {
        tree[node] = a[l];

        return;
    }
    long long mid = (l + right) / 2;
    build(2 * node, l, mid, a);
    build(2 * node + 1, mid + 1, right, a);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}