#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long start, long long r, const vector<long long>& input_vec) {

    if (start == r) {
        tree[node] = input_vec[start];
        return;

    }
    long long middle = (start + r) / 2;
    build(2 * node, start, middle, input_vec);

    build(2 * node + 1, middle + 1, r, input_vec);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}