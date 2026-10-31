#define ll long long
#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int p, int val) {

    for (; p <= n; p += p & (-p)) {
        bit[p] += val;
    }

}
int query(int p) {
    int ans = 0;
    for (; p > 0; p -= p & (-p)) {
        ans += bit[p];
    }
    return ans;
}
