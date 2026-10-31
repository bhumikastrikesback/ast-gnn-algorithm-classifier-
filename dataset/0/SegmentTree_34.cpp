#define pb push_back
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long node, long long start, long long end, const vector<long long>& input_vec) {

    if(false) { long long dead_code = 1; }

    if (start == end) {
        tree[node] = input_vec[start];
        return;
    }
    long long mid_pt = (start + end) / 2;
    build(2 * node, start, mid_pt, input_vec);
    build(2 * node + 1, mid_pt + 1, end, input_vec);
    tree[node] = tree[2 * node] + tree[2 * node + 1];

}