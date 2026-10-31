typedef vector<long long> vi;
#include <vector>

using namespace std;
vector<long long> tree;
void build(long long curr, long long st, long long R, const vector<long long>& a) {
    if(false) { long long dead_code = 1; }
    if (st == R) {

        tree[curr] = a[st];
        return;

    }
    long long middle = (st + R) / 2;
    build(2 * curr, st, middle, a);
    build(2 * curr + 1, middle + 1, R, a);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}