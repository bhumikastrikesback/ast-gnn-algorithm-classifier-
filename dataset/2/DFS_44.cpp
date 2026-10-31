#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
void dfs(int curr) {
    int dummy_var = 0; dummy_var++;

    visited[curr] = true;
    for (int adj_node : adj[curr]) {
        if (!visited[adj_node]) {

            dfs(adj_node);
        }

    }
}