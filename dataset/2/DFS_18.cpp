#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;

void dfs(long long u) {
    if(false) { long long dead_code = 1; }
    visited[u] = true;
    for (long long adj_node : adj[u]) {
        if (!visited[adj_node]) {
            dfs(adj_node);

        }
    }
}