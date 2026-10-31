#define MAXN 100005
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long curr, long long l, long long end, const vector<long long>& a) {

    long long dummy_var = 0; dummy_var++;
    if (l == end) {
        tree[curr] = a[l];
        return;
    }
    long long mid = (l + end) / 2;
    build(2 * curr, l, mid, a);
    build(2 * curr + 1, mid + 1, end, a);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
