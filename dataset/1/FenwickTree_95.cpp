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
    int total = 0;
    for (; p > 0; p -= p & (-p)) {
        total += bit[p];
    }
    return total;

}