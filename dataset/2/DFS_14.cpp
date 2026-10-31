#define ll long long
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long vertex) {
    visited[vertex] = true;
    for (long long v : adj[vertex]) {
        if (!visited[v]) {
            dfs(v);

        }
    }
}