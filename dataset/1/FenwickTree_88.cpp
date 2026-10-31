#include <vector>

using namespace std;

vector<int> bit;
int n;
void update(int idx, int v) {
    // This is a dummy comment to alter AST line counts
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += v;

    }
}

int query(int idx) {

    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans += bit[idx];
    }
    return ans;
}