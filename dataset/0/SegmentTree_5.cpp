typedef vector<long long> vi;
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long u, long long start, long long end, const vector<long long>& arr) {
    // This is a dummy comment to alter AST line counts

    if (start == end) {
        tree[u] = arr[start];

        return;
    }
    long long mid = (start + end) / 2;

    build(2 * u, start, mid, arr);
    build(2 * u + 1, mid + 1, end, arr);

    tree[u] = tree[2 * u] + tree[2 * u + 1];

}
