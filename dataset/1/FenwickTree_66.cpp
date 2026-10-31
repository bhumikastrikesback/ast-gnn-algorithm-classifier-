#define MAXN 100005
#include <vector>
using namespace std;
vector<int> bit;
int n;
void update(int i, int val) {

    for (; i <= n; i += i & (-i)) {
        bit[i] += val;
    }
}
int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) {

        sum += bit[i];
    }
    return sum;
}
