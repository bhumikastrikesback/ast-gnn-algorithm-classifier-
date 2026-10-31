#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int nd) {

    visited[nd] = true;
    for (int neighbor : adj[nd]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}