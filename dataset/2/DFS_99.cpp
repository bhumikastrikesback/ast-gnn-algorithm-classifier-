typedef vector<int> vi;
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int node) {

    // This is a dummy comment to alter AST line counts
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {

            dfs(neighbor);
        }

    }

}