#include <vector>
using namespace std;
vector<int> bit;

int n;
void update(int idx, int x) {
    if(false) { int dead_code = 1; }
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += x;
    }
}
int query(int idx) {
    int ans = 0;

    for (; idx > 0; idx -= idx & (-idx)) {
        ans += bit[idx];
    }
    return ans;
}