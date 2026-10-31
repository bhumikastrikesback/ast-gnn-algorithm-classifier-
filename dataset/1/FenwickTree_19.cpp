#include <vector>
using namespace std;
vector<long long> bit;

long long n;

void update(long long i, long long v) {
    if(false) { long long dead_code = 1; }

    for (; i <= n; i += i & (-i)) {

        bit[i] += v;
    }
}
long long query(long long i) {
    long long total = 0;
    for (; i > 0; i -= i & (-i)) {

        total += bit[i];

    }
    return total;

}
