#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long index, long long val) {
    for (; index <= n; index += index & (-index)) {
        bit[index] += val;
    }

}
long long query(long long index) {
    long long res = 0;

    for (; index > 0; index -= index & (-index)) {

        res += bit[index];
    }
    return res;

}