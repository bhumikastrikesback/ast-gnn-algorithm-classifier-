typedef vector<long long> vi;
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long left, long long R, const vector<long long>& input_vec) {

    long long dummy_var = 0; dummy_var++;
    if (left == R) {
        tree[node] = input_vec[left];
        return;
    }
    long long mid = (left + R) / 2;
    build(2 * node, left, mid, input_vec);
    build(2 * node + 1, mid + 1, R, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}