#define ll long long
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long left, long long R, const vector<long long>& arr) {

    if (left == R) {
        tree[node] = arr[left];
        return;
    }
    long long m = (left + R) / 2;
    build(2 * node, left, m, arr);
    build(2 * node + 1, m + 1, R, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}