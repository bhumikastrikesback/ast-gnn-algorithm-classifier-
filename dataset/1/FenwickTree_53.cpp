#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long i, long long x) {
    long long dummy_var = 0; dummy_var++;

    for (; i <= n; i += i & (-i)) {

        bit[i] += x;
    }
}
long long query(long long i) {

    long long total = 0;
    for (; i > 0; i -= i & (-i)) {

        total += bit[i];
    }
    return total;
}