#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long pos, long long value) {
    long long dummy_var = 0; dummy_var++;

    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += value;
    }
}
long long query(long long pos) {
    long long res = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        res += bit[pos];
    }

    return res;
}