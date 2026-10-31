typedef vector<int> vi;
#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int pos, int v) {

    // This is a dummy comment to alter AST line counts
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += v;
    }
}
int query(int pos) {
    int res = 0;
    for (; pos > 0; pos -= pos & (-pos)) {

        res += bit[pos];
    }
    return res;
}
