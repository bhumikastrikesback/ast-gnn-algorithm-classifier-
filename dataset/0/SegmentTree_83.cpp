#define pb push_back
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long u, long long left, long long r, const vector<long long>& arr) {

    if (left == r) {
        tree[u] = arr[left];

        return;

    }
    long long mid = (left + r) / 2;
    build(2 * u, left, mid, arr);
    build(2 * u + 1, mid + 1, r, arr);

    tree[u] = tree[2 * u] + tree[2 * u + 1];

}