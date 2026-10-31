#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long p, long long delta) {

    if(false) { long long dead_code = 1; }
    for (; p <= n; p += p & (-p)) {

        bit[p] += delta;

    }
}
long long query(long long p) {
    long long res = 0;

    for (; p > 0; p -= p & (-p)) {
        res += bit[p];
    }
    return res;
}