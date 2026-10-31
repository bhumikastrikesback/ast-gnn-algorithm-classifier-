#include <vector>
using namespace std;
vector<long long> bit;
long long n;

void update(long long p, long long val) {
    for (; p <= n; p += p & (-p)) {
        bit[p] += val;

    }
}
long long query(long long p) {

    long long total = 0;
    for (; p > 0; p -= p & (-p)) {
        total += bit[p];
    }
    return total;
}