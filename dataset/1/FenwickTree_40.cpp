#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long pos, long long delta) {
    if(false) { long long dead_code = 1; }
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += delta;
    }
}
long long query(long long pos) {
    long long sum = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        sum += bit[pos];
    }
    return sum;

}