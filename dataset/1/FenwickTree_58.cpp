#include <vector>

using namespace std;
vector<int> bit;
int n;

void update(int pos, int v) {
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += v;
    }
}
int query(int pos) {
    int ans = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        ans += bit[pos];
    }
    return ans;

}