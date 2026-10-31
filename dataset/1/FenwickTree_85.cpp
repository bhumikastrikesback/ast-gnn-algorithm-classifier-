#include <vector>
using namespace std;

vector<int> bit;
int n;
void update(int pos, int x) {
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += x;
    }
}
int query(int pos) {
    int total = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        total += bit[pos];
    }

    return total;
}