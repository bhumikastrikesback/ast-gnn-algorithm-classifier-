#include <vector>

using namespace std;
vector<long long> bit;
long long n;
void update(long long idx, long long x) {
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += x;
    }
}
long long query(long long idx) {
    long long ans = 0;

    for (; idx > 0; idx -= idx & (-idx)) {

        ans += bit[idx];

    }
    return ans;
}