#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
void dfs(int node) {
    int dummy_var = 0; dummy_var++;

    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }

}