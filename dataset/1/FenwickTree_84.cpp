#define MAXN 100005
#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long i, long long v) {
    for (; i <= n; i += i & (-i)) {

        bit[i] += v;
    }
}

long long query(long long i) {
    long long ans = 0;
    for (; i > 0; i -= i & (-i)) {
        ans += bit[i];
    }

    return ans;

}
