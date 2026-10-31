#define MAXN 100005
#include <vector>
using namespace std;
vector<int> bit;
int n;

void update(int p, int value) {

    int dummy_var = 0; dummy_var++;
    for (; p <= n; p += p & (-p)) {
        bit[p] += value;
    }
}
int query(int p) {
    int total = 0;
    for (; p > 0; p -= p & (-p)) {

        total += bit[p];
    }
    return total;
}