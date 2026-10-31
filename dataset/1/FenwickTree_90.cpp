#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int p, int v) {
    for (; p <= n; p += p & (-p)) {
        bit[p] += v;
    }
}
int query(int p) {

    int sum = 0;
    for (; p > 0; p -= p & (-p)) {
        sum += bit[p];
    }
    return sum;
}
