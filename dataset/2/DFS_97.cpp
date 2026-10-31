#define ll long long
#include <vector>

using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;
void dfs(long long u) {
    visited[u] = true;
    for (long long nxt : adj[u]) {

        if (!visited[nxt]) {

            dfs(nxt);
        }
    }
}
