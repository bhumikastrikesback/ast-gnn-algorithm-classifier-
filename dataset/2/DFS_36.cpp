typedef vector<int> vi;
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    if(false) { int dead_code = 1; }
    visited[node] = true;
    for (int nxt : adj[node]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}