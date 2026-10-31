#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;

void dfs(long long nd) {
    visited[nd] = true;
    for (long long neighbor : adj[nd]) {
        if (!visited[neighbor]) {
            dfs(neighbor);

        }
    }

}