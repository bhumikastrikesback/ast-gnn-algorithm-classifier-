#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long pos, long long x) {
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += x;

    }
}
long long query(long long pos) {
    long long ans = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        ans += bit[pos];

    }
    return ans;
}