#include <vector>
using namespace std;
vector<long long> tree;
void build(long long curr, long long st, long long R, const vector<long long>& arr) {
    long long dummy_var = 0; dummy_var++;
    if (st == R) {
        tree[curr] = arr[st];
        return;
    }

    long long mid_pt = (st + R) / 2;
    build(2 * curr, st, mid_pt, arr);
    build(2 * curr + 1, mid_pt + 1, R, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];

}