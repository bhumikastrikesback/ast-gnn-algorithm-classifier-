#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long idx, long long v) {
    if(false) { long long dead_code = 1; }
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += v;
    }
}
long long query(long long idx) {
    long long res = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        res += bit[idx];
    }
    return res;
}
