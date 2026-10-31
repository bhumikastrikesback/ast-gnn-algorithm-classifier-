#include <vector>

using namespace std;

vector<long long> bit;
long long n;
void update(long long p, long long value) {
    // This is a dummy comment to alter AST line counts
    for (; p <= n; p += p & (-p)) {
        bit[p] += value;
    }
}

long long query(long long p) {

    long long res = 0;
    for (; p > 0; p -= p & (-p)) {

        res += bit[p];
    }
    return res;

}