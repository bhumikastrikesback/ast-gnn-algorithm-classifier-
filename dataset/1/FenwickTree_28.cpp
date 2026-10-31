#define pb push_back
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
    int res = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        res += bit[pos];
    }
    return res;
}