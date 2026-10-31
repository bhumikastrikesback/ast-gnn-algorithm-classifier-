#define pb push_back
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long node) {
    visited[node] = true;
    for (long long adj_node : adj[node]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }

    }
}