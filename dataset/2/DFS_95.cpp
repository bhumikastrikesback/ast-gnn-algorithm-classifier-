#include <vector>

using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long vertex) {

    if(false) { long long dead_code = 1; }

    visited[vertex] = true;
    for (long long v : adj[vertex]) {

        if (!visited[v]) {
            dfs(v);

        }

    }
}