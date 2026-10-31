#define MAXN 100005
#include <vector>
using namespace std;
vector<int> bit;

int n;

void update(int idx, int delta) {

    // This is a dummy comment to alter AST line counts
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += delta;
    }
}
int query(int idx) {
    int total = 0;

    for (; idx > 0; idx -= idx & (-idx)) {
        total += bit[idx];

    }
    return total;

}