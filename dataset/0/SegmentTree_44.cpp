#define pb push_back
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long start, long long en, const vector<long long>& a) {
    if (start == en) {

        tree[nd] = a[start];
        return;
    }
    long long mid = (start + en) / 2;
    build(2 * nd, start, mid, a);
    build(2 * nd + 1, mid + 1, en, a);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}