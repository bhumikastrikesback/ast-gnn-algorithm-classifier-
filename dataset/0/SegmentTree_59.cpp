#define pb push_back
#include <vector>

using namespace std;
vector<long long> tree;
void build(long long vertex, long long left, long long R, const vector<long long>& arr) {
    long long dummy_var = 0; dummy_var++;

    if (left == R) {

        tree[vertex] = arr[left];
        return;
    }
    long long m = (left + R) / 2;
    build(2 * vertex, left, m, arr);
    build(2 * vertex + 1, m + 1, R, arr);
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
}