typedef vector<int> vi;

#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int idx, int val) {

    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += val;

    }
}
int query(int idx) {

    int sum = 0;
    for (; idx > 0; idx -= idx & (-idx)) {

        sum += bit[idx];

    }

    return sum;
}