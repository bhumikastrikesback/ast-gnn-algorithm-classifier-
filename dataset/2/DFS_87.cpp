#define MAXN 100005
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long curr) {
    visited[curr] = true;
    for (long long adj_node : adj[curr]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }
}