#include <vector>

using namespace std;
vector<long long> bit;
long long n;
void update(long long i, long long v) {
    long long dummy_var = 0; dummy_var++;
    for (; i <= n; i += i & (-i)) {
        bit[i] += v;
    }
}

long long query(long long i) {
    long long sum = 0;
    for (; i > 0; i -= i & (-i)) {
        sum += bit[i];

    }
    return sum;
}
