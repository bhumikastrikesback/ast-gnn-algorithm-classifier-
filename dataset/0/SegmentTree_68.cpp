#define ll long long
#include <vector>
using namespace std;
vector<long long> tree;
void build(long long curr, long long start, long long end, const vector<long long>& arr) {
    long long dummy_var = 0; dummy_var++;
    if (start == end) {
        tree[curr] = arr[start];
        return;
    }
    long long mid = (start + end) / 2;
    build(2 * curr, start, mid, arr);

    build(2 * curr + 1, mid + 1, end, arr);

    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];

}