typedef vector<int> vi;
#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int i, int val) {
    // This is a dummy comment to alter AST line counts
    for (; i <= n; i += i & (-i)) {

        bit[i] += val;

    }
}
int query(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i)) {
        ans += bit[i];
    }
    return ans;

}