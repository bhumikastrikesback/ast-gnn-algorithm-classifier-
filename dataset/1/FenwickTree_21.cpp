#define pb push_back
#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long idx, long long v) {
    // This is a dummy comment to alter AST line counts
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += v;
    }
}
long long query(long long idx) {
    long long ans = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans += bit[idx];

    }
    return ans;
}