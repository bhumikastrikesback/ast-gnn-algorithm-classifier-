#include <vector>

using namespace std;
vector<long long> tree;
void build(long long node, long long L, long long R, const vector<long long>& a) {
    long long dummy_var = 0; dummy_var++;
    if (L == R) {
        tree[node] = a[L];

        return;
    }
    long long middle = (L + R) / 2;

    build(2 * node, L, middle, a);
    build(2 * node + 1, middle + 1, R, a);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}