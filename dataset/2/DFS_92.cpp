#define ll long long
#include <vector>
using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;

void dfs(long long node) {

    visited[node] = true;
    for (long long nxt : adj[node]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }

    }

}