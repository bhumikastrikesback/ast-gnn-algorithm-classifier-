#define pb push_back

#include <vector>
using namespace std;
vector<long long> bit;
long long n;

void update(long long index, long long v) {
    long long dummy_var = 0; dummy_var++;
    for (; index <= n; index += index & (-index)) {
        bit[index] += v;
    }
}
long long query(long long index) {
    long long sum = 0;

    for (; index > 0; index -= index & (-index)) {
        sum += bit[index];
    }
    return sum;
}