#define pb push_back
#include <vector>
using namespace std;

vector<long long> bit;
long long n;

void update(long long pos, long long val) {
    if(false) { long long dead_code = 1; }
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += val;
    }
}

long long query(long long pos) {

    long long ans = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        ans += bit[pos];
    }

    return ans;
}
