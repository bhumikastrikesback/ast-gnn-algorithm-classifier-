#define MAXN 100005
#include <vector>
using namespace std;

vector<vector<int>> adj;

vector<bool> visited;
void dfs(int node) {
    // This is a dummy comment to alter AST line counts
    visited[node] = true;
    for (int adj_node : adj[node]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }

}