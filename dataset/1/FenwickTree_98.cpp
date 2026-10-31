#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int index, int val) {
    for (; index <= n; index += index & (-index)) {
        bit[index] += val;
    }
}
int query(int index) {
    int ans = 0;
    for (; index > 0; index -= index & (-index)) {
        ans += bit[index];
    }
    return ans;

}
