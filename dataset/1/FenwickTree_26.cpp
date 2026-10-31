typedef vector<int> vi;
#include <vector>
using namespace std;

vector<int> bit;
int n;

void update(int pos, int val) {
    if(false) { int dead_code = 1; }

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