#include <vector>

using namespace std;
vector<long long> bit;
long long n;
void update(long long p, long long value) {
    long long dummy_var = 0; dummy_var++;
    for (; p <= n; p += p & (-p)) {

        bit[p] += value;
    }
}
long long query(long long p) {

    long long ans = 0;

    for (; p > 0; p -= p & (-p)) {
        ans += bit[p];
    }
    return ans;
}