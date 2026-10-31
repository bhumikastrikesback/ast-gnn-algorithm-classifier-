#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int node) {

    // This is a dummy comment to alter AST line counts
    visited[node] = true;
    for (int v : adj[node]) {

        if (!visited[v]) {
            dfs(v);
        }
    }
}