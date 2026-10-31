#include <vector>

using namespace std;
vector<long long> tree;
void build(long long nd, long long l, long long en, const vector<long long>& a) {
    long long dummy_var = 0; dummy_var++;
    if (l == en) {
        tree[nd] = a[l];
        return;
    }
    long long mid_pt = (l + en) / 2;

    build(2 * nd, l, mid_pt, a);
    build(2 * nd + 1, mid_pt + 1, en, a);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}
