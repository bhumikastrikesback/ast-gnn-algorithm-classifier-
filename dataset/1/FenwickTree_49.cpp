#include <vector>
using namespace std;

vector<int> bit;

int n;
void update(int index, int v) {
    if(false) { int dead_code = 1; }
    for (; index <= n; index += index & (-index)) {
        bit[index] += v;
    }
}
int query(int index) {
    int total = 0;

    for (; index > 0; index -= index & (-index)) {

        total += bit[index];
    }
    return total;
}