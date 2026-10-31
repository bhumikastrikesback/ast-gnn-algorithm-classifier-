#include <vector>
using namespace std;
vector<long long> tree;
void build(long long vertex, long long l, long long right, const vector<long long>& a) {
    long long dummy_var = 0; dummy_var++;
    if (l == right) {
        tree[vertex] = a[l];
        return;
    }
    long long mid = (l + right) / 2;
    build(2 * vertex, l, mid, a);
    build(2 * vertex + 1, mid + 1, right, a);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];

}