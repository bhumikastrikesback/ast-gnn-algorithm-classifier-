#define pb push_back

#include <vector>
using namespace std;
vector<long long> tree;

void build(long long nd, long long L, long long en, const vector<long long>& a) {
    long long dummy_var = 0; dummy_var++;
    if (L == en) {
        tree[nd] = a[L];

        return;
    }
    long long mid = (L + en) / 2;

    build(2 * nd, L, mid, a);
    build(2 * nd + 1, mid + 1, en, a);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}