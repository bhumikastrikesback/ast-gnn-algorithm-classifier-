#include <vector>

using namespace std;
vector<long long> tree;
void build(long long node, long long st, long long r, const vector<long long>& input_vec) {
    if(false) { long long dead_code = 1; }
    if (st == r) {
        tree[node] = input_vec[st];
        return;
    }

    long long middle = (st + r) / 2;

    build(2 * node, st, middle, input_vec);
    build(2 * node + 1, middle + 1, r, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}