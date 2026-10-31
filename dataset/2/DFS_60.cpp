#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long u) {

    visited[u] = true;

    for (long long v : adj[u]) {

        if (!visited[v]) {
            dfs(v);
        }

    }
}
