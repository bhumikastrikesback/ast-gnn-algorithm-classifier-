#include <vector>
using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;
void dfs(long long u) {

    long long dummy_var = 0; dummy_var++;
    visited[u] = true;
    for (long long neighbor : adj[u]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}