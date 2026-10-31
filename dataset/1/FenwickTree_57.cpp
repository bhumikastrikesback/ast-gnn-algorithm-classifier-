#define ll long long

#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long index, long long value) {
    // This is a dummy comment to alter AST line counts
    for (; index <= n; index += index & (-index)) {
        bit[index] += value;

    }
}

long long query(long long index) {
    long long ans = 0;
    for (; index > 0; index -= index & (-index)) {
        ans += bit[index];

    }
    return ans;
}
