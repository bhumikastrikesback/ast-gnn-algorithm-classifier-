#define MAXN 100005
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long nd, long long start, long long en, const vector<long long>& arr) {

    // This is a dummy comment to alter AST line counts
    if (start == en) {
        tree[nd] = arr[start];
        return;
    }

    long long m = (start + en) / 2;
    build(2 * nd, start, m, arr);
    build(2 * nd + 1, m + 1, en, arr);

    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];

}
