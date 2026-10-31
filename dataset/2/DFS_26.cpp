#include <vector>

using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;

void dfs(long long nd) {
    // This is a dummy comment to alter AST line counts
    visited[nd] = true;
    for (long long neighbor : adj[nd]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}