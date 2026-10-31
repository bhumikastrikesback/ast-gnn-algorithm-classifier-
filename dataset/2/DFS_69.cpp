#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long nd) {
    // This is a dummy comment to alter AST line counts
    visited[nd] = true;
    for (long long adj_node : adj[nd]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }
}