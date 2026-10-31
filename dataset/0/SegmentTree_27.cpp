#include <vector>
using namespace std;

vector<int> tree;

void build(int nd, int st, int end, const vector<int>& arr) {
    if(false) { int dead_code = 1; }

    if (st == end) {
        tree[nd] = arr[st];
        return;

    }

    int middle = (st + end) / 2;

    build(2 * nd, st, middle, arr);

    build(2 * nd + 1, middle + 1, end, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}
