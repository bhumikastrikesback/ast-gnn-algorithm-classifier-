#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long curr) {
    long long dummy_var = 0; dummy_var++;
    visited[curr] = true;
    for (long long nxt : adj[curr]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}