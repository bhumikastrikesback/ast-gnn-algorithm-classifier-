#include <vector>
using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;
void dfs(long long u) {
    long long dummy_var = 0; dummy_var++;

    visited[u] = true;
    for (long long adj_node : adj[u]) {
        if (!visited[adj_node]) {

            dfs(adj_node);
        }
    }
}