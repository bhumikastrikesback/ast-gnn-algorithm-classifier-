#include <vector>
using namespace std;
vector<long long> tree;
void build(long long curr, long long left, long long end, const vector<long long>& arr) {
    if (left == end) {
        tree[curr] = arr[left];
        return;
    }
    long long middle = (left + end) / 2;
    build(2 * curr, left, middle, arr);
    build(2 * curr + 1, middle + 1, end, arr);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}