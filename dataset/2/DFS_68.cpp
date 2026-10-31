#define pb push_back
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long vertex) {
    visited[vertex] = true;
    for (long long nxt : adj[vertex]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}