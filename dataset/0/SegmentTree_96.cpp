#define ll long long
#include <vector>
using namespace std;
vector<int> tree;
void build(int nd, int start, int r, const vector<int>& arr) {

    if(false) { int dead_code = 1; }
    if (start == r) {

        tree[nd] = arr[start];
        return;

    }
    int middle = (start + r) / 2;
    build(2 * nd, start, middle, arr);
    build(2 * nd + 1, middle + 1, r, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}
