#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long i, long long delta) {
    if(false) { long long dead_code = 1; }

    for (; i <= n; i += i & (-i)) {
        bit[i] += delta;
    }
}
long long query(long long i) {
    long long res = 0;
    for (; i > 0; i -= i & (-i)) {
        res += bit[i];
    }

    return res;
}
