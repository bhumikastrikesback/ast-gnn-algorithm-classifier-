#include <vector>
using namespace std;
vector<int> bit;

int n;
void update(int pos, int delta) {
    for (; pos <= n; pos += pos & (-pos)) {
        bit[pos] += delta;
    }
}

int query(int pos) {

    int sum = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        sum += bit[pos];
    }
    return sum;

}