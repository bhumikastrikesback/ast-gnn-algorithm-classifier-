#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int vertex) {

    visited[vertex] = true;
    for (int v : adj[vertex]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}