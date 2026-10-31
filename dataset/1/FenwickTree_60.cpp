#include <vector>
using namespace std;
vector<int> bit;

int n;
void update(int idx, int delta) {
    for (; idx <= n; idx += idx & (-idx)) {

        bit[idx] += delta;
    }
}

int query(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans += bit[idx];
    }
    return ans;
}