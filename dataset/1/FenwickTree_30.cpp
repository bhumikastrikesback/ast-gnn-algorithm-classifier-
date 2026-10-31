#define ll long long
#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long pos, long long value) {
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += value;
    }
}
long long query(long long pos) {
    long long total = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        total += bit[pos];
    }
    return total;
}