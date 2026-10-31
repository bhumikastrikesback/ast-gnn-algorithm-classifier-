#define pb push_back
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long curr, long long st, long long end, const vector<long long>& input_vec) {
    if(false) { long long dead_code = 1; }
    if (st == end) {
        tree[curr] = input_vec[st];
        return;
    }
    long long middle = (st + end) / 2;
    build(2 * curr, st, middle, input_vec);

    build(2 * curr + 1, middle + 1, end, input_vec);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
