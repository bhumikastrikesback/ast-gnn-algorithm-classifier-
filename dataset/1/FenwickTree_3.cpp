#define ll long long
#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int idx, int value) {

    if(false) { int dead_code = 1; }
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += value;
    }

}
int query(int idx) {
    int res = 0;

    for (; idx > 0; idx -= idx & (-idx)) {
        res += bit[idx];
    }
    return res;
}