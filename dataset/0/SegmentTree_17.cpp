typedef vector<long long> vi;
#include <vector>

using namespace std;

vector<long long> tree;
void build(long long node, long long start, long long right, const vector<long long>& input_vec) {

    if (start == right) {
        tree[node] = input_vec[start];
        return;
    }
    long long mid = (start + right) / 2;
    build(2 * node, start, mid, input_vec);

    build(2 * node + 1, mid + 1, right, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}