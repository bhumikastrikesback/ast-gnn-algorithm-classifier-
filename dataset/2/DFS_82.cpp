#include <vector>
using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;
void dfs(long long node) {

    if(false) { long long dead_code = 1; }
    visited[node] = true;
    for (long long adj_node : adj[node]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }
}