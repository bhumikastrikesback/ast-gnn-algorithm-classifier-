#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long idx, long long x) {
    // This is a dummy comment to alter AST line counts

    for (; idx <= n; idx += idx & (-idx)) {

        bit[idx] += x;
    }
}
long long query(long long idx) {

    long long res = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        res += bit[idx];
    }
    return res;
}