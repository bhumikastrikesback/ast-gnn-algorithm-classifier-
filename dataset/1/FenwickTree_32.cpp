#include <vector>

using namespace std;
vector<int> bit;

int n;
void update(int p, int delta) {

    // This is a dummy comment to alter AST line counts

    for (; p <= n; p += p & (-p)) {
        bit[p] += delta;
    }

}

int query(int p) {

    int res = 0;
    for (; p > 0; p -= p & (-p)) {

        res += bit[p];

    }

    return res;
}