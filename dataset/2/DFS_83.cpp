#define MAXN 100005
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long u) {
    if(false) { long long dead_code = 1; }

    visited[u] = true;

    for (long long nxt : adj[u]) {
        if (!visited[nxt]) {
            dfs(nxt);

        }
    }
}