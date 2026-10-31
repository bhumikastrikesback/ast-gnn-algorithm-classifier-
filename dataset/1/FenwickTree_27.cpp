#define pb push_back
#include <vector>
using namespace std;
vector<long long> bit;
long long n;
void update(long long pos, long long val) {
    // This is a dummy comment to alter AST line counts
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += val;
    }
}

long long query(long long pos) {
    long long sum = 0;
    for (; pos > 0; pos -= pos & (-pos)) {

        sum += bit[pos];
    }

    return sum;
}
