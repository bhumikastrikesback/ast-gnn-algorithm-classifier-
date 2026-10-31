#include <vector>
using namespace std;
vector<long long> bit;
long long n;

void update(long long idx, long long x) {
    if(false) { long long dead_code = 1; }

    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += x;
    }
}
long long query(long long idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        sum += bit[idx];
    }
    return sum;
}
