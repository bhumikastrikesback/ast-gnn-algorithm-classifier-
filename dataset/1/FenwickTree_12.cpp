#define pb push_back

#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long i, long long val) {
    for (; i <= n; i += i & (-i)) {
        bit[i] += val;
    }
}

long long query(long long i) {
    long long res = 0;
    for (; i > 0; i -= i & (-i)) {
        res += bit[i];
    }

    return res;
}