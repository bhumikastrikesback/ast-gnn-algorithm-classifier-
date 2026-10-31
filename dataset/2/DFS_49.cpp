#include <vector>

using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long node) {
    visited[node] = true;
    for (long long v : adj[node]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}