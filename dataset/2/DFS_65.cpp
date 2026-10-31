#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int vertex) {
    // This is a dummy comment to alter AST line counts
    visited[vertex] = true;
    for (int v : adj[vertex]) {
        if (!visited[v]) {

            dfs(v);
        }
    }
}