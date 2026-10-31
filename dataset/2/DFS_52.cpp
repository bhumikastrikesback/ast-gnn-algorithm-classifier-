#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int curr) {
    visited[curr] = true;
    for (int v : adj[curr]) {
        if (!visited[v]) {
            dfs(v);
        }

    }
}