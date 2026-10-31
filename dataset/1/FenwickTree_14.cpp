#include <vector>

using namespace std;
vector<int> bit;

int n;

void update(int idx, int v) {

    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += v;
    }
}
int query(int idx) {
    int total = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        total += bit[idx];
    }
    return total;
}