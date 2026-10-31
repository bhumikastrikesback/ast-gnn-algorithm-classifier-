#define ll long long
#include <vector>

using namespace std;
vector<long long> bit;
long long n;
void update(long long idx, long long val) {
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += val;

    }
}
long long query(long long idx) {
    long long res = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        res += bit[idx];

    }
    return res;
}