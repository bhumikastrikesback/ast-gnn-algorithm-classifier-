#define MAXN 100005
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }

    }
}
