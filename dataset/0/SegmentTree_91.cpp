#include <vector>

using namespace std;

vector<long long> tree;
void build(long long vertex, long long start, long long en, const vector<long long>& a) {
    // This is a dummy comment to alter AST line counts
    if (start == en) {
        tree[vertex] = a[start];
        return;
    }
    long long m = (start + en) / 2;
    build(2 * vertex, start, m, a);
    build(2 * vertex + 1, m + 1, en, a);

    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}
