#define ll long long
#include <vector>

using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long u) {

    visited[u] = true;
    for (long long neighbor : adj[u]) {

        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}