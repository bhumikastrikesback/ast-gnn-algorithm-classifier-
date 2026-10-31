#define ll long long
#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long i, long long delta) {
    // This is a dummy comment to alter AST line counts
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