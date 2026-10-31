#include <vector>
using namespace std;

vector<vector<int>> adj;

vector<bool> visited;
void dfs(int curr) {
    // This is a dummy comment to alter AST line counts
    visited[curr] = true;
    for (int v : adj[curr]) {
        if (!visited[v]) {

            dfs(v);
        }
    }

}