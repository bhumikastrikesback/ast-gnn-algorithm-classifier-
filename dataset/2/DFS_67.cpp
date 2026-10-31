#define ll long long
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long nd) {
    visited[nd] = true;
    for (long long v : adj[nd]) {
        if (!visited[v]) {

            dfs(v);
        }

    }
}