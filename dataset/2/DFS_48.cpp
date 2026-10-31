#define ll long long

#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long vertex) {
    visited[vertex] = true;
    for (long long adj_node : adj[vertex]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }
}