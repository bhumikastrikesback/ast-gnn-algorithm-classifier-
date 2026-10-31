typedef vector<long long> vi;
#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long pos, long long delta) {
    long long dummy_var = 0; dummy_var++;

    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += delta;
    }
}
long long query(long long pos) {
    long long total = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        total += bit[pos];

    }
    return total;
}