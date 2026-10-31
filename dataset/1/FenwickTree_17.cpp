#define MAXN 100005
#include <vector>

using namespace std;

vector<long long> bit;
long long n;
void update(long long index, long long x) {
    if(false) { long long dead_code = 1; }
    for (; index <= n; index += index & (-index)) {
        bit[index] += x;
    }
}
long long query(long long index) {
    long long ans = 0;
    for (; index > 0; index -= index & (-index)) {

        ans += bit[index];
    }
    return ans;
}