#define pb push_back
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int u) {

    if(false) { int dead_code = 1; }

    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}