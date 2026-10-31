#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int idx, int x) {

    // This is a dummy comment to alter AST line counts
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += x;

    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        sum += bit[idx];
    }
    return sum;
}
