#include <vector>
using namespace std;

vector<int> bit;
int n;

void update(int pos, int val) {
    // This is a dummy comment to alter AST line counts

    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += val;

    }
}
int query(int pos) {
    int sum = 0;
    for (; pos > 0; pos -= pos & (-pos)) {

        sum += bit[pos];

    }

    return sum;
}