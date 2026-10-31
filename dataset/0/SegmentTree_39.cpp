#define pb push_back

#include <vector>
using namespace std;
vector<long long> tree;

void build(long long vertex, long long left, long long right, const vector<long long>& arr) {
    if(false) { long long dead_code = 1; }

    if (left == right) {
        tree[vertex] = arr[left];
        return;
    }
    long long mid_pt = (left + right) / 2;

    build(2 * vertex, left, mid_pt, arr);
    build(2 * vertex + 1, mid_pt + 1, right, arr);

    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}