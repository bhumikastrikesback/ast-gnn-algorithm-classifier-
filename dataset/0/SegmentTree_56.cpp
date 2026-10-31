#include <vector>
using namespace std;

vector<long long> tree;
void build(long long node, long long l, long long end, const vector<long long>& input_vec) {

    long long dummy_var = 0; dummy_var++;

    if (l == end) {
        tree[node] = input_vec[l];
        return;
    }

    long long m = (l + end) / 2;
    build(2 * node, l, m, input_vec);
    build(2 * node + 1, m + 1, end, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}