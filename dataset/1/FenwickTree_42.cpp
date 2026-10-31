#define MAXN 100005

#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int index, int val) {
    int dummy_var = 0; dummy_var++;
    for (; index <= n; index += index & (-index)) {
        bit[index] += val;

    }
}
int query(int index) {
    int total = 0;

    for (; index > 0; index -= index & (-index)) {

        total += bit[index];
    }
    return total;
}