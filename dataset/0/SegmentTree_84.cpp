#include <vector>
using namespace std;
vector<long long> tree;
void build(long long vertex, long long l, long long en, const vector<long long>& input_vec) {
    if (l == en) {
        tree[vertex] = input_vec[l];

        return;

    }
    long long m = (l + en) / 2;
    build(2 * vertex, l, m, input_vec);

    build(2 * vertex + 1, m + 1, en, input_vec);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}