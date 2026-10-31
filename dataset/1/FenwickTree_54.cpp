#define ll long long
#include <vector>
using namespace std;

vector<int> bit;
int n;
void update(int index, int val) {

    for (; index <= n; index += index & (-index)) {

        bit[index] += val;
    }
}
int query(int index) {

    int res = 0;
    for (; index > 0; index -= index & (-index)) {
        res += bit[index];
    }
    return res;
}