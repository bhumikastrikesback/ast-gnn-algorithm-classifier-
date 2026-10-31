#define pb push_back

#include <vector>

using namespace std;

vector<long long> tree;
void build(long long curr, long long st, long long en, const vector<long long>& a) {
    // This is a dummy comment to alter AST line counts
    if (st == en) {
        tree[curr] = a[st];
        return;
    }
    long long middle = (st + en) / 2;
    build(2 * curr, st, middle, a);

    build(2 * curr + 1, middle + 1, en, a);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}