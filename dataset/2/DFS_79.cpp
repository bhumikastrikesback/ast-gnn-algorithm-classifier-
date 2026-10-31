#define pb push_back
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int adj_node : adj[node]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }
}