#include <vector>
using namespace std;

vector<vector<long long>> adj;
vector<bool> visited;

void dfs(long long curr) {
    visited[curr] = true;
    for (long long nxt : adj[curr]) {
        if (!visited[nxt]) {

            dfs(nxt);
        }
    }

}