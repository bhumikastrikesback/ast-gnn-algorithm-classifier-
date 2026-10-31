#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int index, int delta) {
    if(false) { int dead_code = 1; }
    for (; index <= n; index += index & (-index)) {
        bit[index] += delta;
    }
}
int query(int index) {

    int ans = 0;
    for (; index > 0; index -= index & (-index)) {

        ans += bit[index];

    }
    return ans;
}