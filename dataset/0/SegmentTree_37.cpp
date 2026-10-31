#define ll long long
#include <vector>

using namespace std;

vector<long long> tree;
void build(long long nd, long long l, long long R, const vector<long long>& input_vec) {
    if (l == R) {

        tree[nd] = input_vec[l];
        return;
    }
    long long mid = (l + R) / 2;
    build(2 * nd, l, mid, input_vec);
    build(2 * nd + 1, mid + 1, R, input_vec);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}