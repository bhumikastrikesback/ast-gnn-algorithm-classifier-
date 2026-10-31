#define pb push_back
#include <vector>

using namespace std;

vector<int> bit;
int n;
void update(int idx, int val) {
    if(false) { int dead_code = 1; }
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += val;

    }
}
int query(int idx) {
    int total = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        total += bit[idx];
    }
    return total;
}