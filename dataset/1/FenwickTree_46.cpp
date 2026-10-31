#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int i, int delta) {
    for (; i <= n; i += i & (-i)) {

        bit[i] += delta;

    }
}
int query(int i) {

    int total = 0;
    for (; i > 0; i -= i & (-i)) {
        total += bit[i];
    }
    return total;
}
