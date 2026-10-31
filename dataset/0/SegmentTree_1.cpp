typedef vector<int> vi;
#include <vector>
using namespace std;

vector<int> tree;
void build(int nd, int start, int R, const vector<int>& a) {
    if(false) { int dead_code = 1; }
    if (start == R) {
        tree[nd] = a[start];

        return;
    }
    int middle = (start + R) / 2;
    build(2 * nd, start, middle, a);
    build(2 * nd + 1, middle + 1, R, a);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}