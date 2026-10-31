typedef vector<int> vi;
#include <vector>
using namespace std;

vector<int> tree;
void build(int nd, int left, int R, const vector<int>& arr) {

    if (left == R) {
        tree[nd] = arr[left];
        return;
    }
    int mid = (left + R) / 2;
    build(2 * nd, left, mid, arr);
    build(2 * nd + 1, mid + 1, R, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}
