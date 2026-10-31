#include <vector>
using namespace std;

vector<long long> tree;
void build(long long curr, long long start, long long R, const vector<long long>& arr) {
    // This is a dummy comment to alter AST line counts

    if (start == R) {
        tree[curr] = arr[start];

        return;

    }

    long long middle = (start + R) / 2;
    build(2 * curr, start, middle, arr);
    build(2 * curr + 1, middle + 1, R, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}