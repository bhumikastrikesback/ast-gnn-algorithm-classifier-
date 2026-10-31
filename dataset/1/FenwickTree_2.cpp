#define ll long long
#include <vector>
using namespace std;

vector<long long> bit;
long long n;
void update(long long idx, long long val) {
    long long dummy_var = 0; dummy_var++;
    for (; idx <= n; idx += idx & (-idx)) {
        bit[idx] += val;
    }

}
long long query(long long idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        sum += bit[idx];
    }
    return sum;
}
