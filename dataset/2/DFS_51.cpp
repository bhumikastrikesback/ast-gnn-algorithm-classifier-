#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int nxt : adj[u]) {

        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}