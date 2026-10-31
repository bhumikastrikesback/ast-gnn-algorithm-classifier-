#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long left, long long end, const vector<long long>& arr) {

    long long dummy_var = 0; dummy_var++;
    if (left == end) {

        tree[nd] = arr[left];
        return;
    }
    long long mid = (left + end) / 2;

    build(2 * nd, left, mid, arr);
    build(2 * nd + 1, mid + 1, end, arr);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}