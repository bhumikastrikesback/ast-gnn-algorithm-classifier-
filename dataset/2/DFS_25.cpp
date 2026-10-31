#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long curr) {
    if(false) { long long dead_code = 1; }
    visited[curr] = true;
    for (long long neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            dfs(neighbor);

        }
    }
}