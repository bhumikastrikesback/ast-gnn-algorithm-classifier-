#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int nd) {
    // This is a dummy comment to alter AST line counts

    visited[nd] = true;
    for (int adj_node : adj[nd]) {
        if (!visited[adj_node]) {

            dfs(adj_node);
        }
    }

}