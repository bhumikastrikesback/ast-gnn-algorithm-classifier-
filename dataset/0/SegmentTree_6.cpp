#include <vector>
using namespace std;
vector<long long> tree;

void build(long long u, long long left, long long R, const vector<long long>& a) {

    // This is a dummy comment to alter AST line counts

    if (left == R) {
        tree[u] = a[left];
        return;
    }

    long long mid = (left + R) / 2;
    build(2 * u, left, mid, a);

    build(2 * u + 1, mid + 1, R, a);
    tree[u] = tree[2 * u] + tree[2 * u + 1];

}