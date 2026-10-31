#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long st, long long right, const vector<long long>& arr) {
    if (st == right) {

        tree[nd] = arr[st];
        return;

    }

    long long m = (st + right) / 2;

    build(2 * nd, st, m, arr);
    build(2 * nd + 1, m + 1, right, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}