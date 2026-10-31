#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int vertex) {
    visited[vertex] = true;
    for (int adj_node : adj[vertex]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }

    }

}
