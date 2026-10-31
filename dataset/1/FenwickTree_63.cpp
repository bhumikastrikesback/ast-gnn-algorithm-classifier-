#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int index, int delta) {
    // This is a dummy comment to alter AST line counts
    for (; index <= n; index += index & (-index)) {
        bit[index] += delta;
    }
}

int query(int index) {

    int res = 0;
    for (; index > 0; index -= index & (-index)) {
        res += bit[index];
    }
    return res;
}