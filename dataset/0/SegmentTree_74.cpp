#include <vector>
using namespace std;

vector<int> tree;
void build(int nd, int start, int R, const vector<int>& input_vec) {
    if (start == R) {
        tree[nd] = input_vec[start];

        return;
    }
    int m = (start + R) / 2;
    build(2 * nd, start, m, input_vec);
    build(2 * nd + 1, m + 1, R, input_vec);
    tree[nd] = tree[2 * nd] + tree[2 * nd + 1];
}