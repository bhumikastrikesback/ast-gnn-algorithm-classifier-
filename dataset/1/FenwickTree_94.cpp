#define ll long long
#include <vector>

using namespace std;

vector<int> bit;
int n;

void update(int i, int val) {
    int dummy_var = 0; dummy_var++;
    for (; i <= n; i += i & (-i)) {
        bit[i] += val;
    }
}
int query(int i) {
    int total = 0;
    for (; i > 0; i -= i & (-i)) {
        total += bit[i];

    }
    return total;
}