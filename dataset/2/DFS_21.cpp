#include <vector>
using namespace std;

vector<vector<long long>> adj;

vector<bool> visited;
void dfs(long long vertex) {
    visited[vertex] = true;
    for (long long neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}