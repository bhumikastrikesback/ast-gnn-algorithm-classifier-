#define pb push_back
#include <vector>

using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long node) {

    if(false) { long long dead_code = 1; }
    visited[node] = true;
    for (long long v : adj[node]) {
        if (!visited[v]) {
            dfs(v);
        }

    }

}