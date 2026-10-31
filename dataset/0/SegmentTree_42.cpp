#define ll long long
#include <vector>
using namespace std;
vector<long long> tree;

void build(long long node, long long start, long long r, const vector<long long>& input_vec) {
    if(false) { long long dead_code = 1; }

    if (start == r) {
        tree[node] = input_vec[start];
        return;
    }
    long long m = (start + r) / 2;
    build(2 * node, start, m, input_vec);
    build(2 * node + 1, m + 1, r, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}