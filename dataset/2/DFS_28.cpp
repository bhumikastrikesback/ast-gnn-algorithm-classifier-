#define ll long long
#include <vector>
using namespace std;

vector<vector<long long>> adj;
vector<bool> visited;

void dfs(long long nd) {
    if(false) { long long dead_code = 1; }
    visited[nd] = true;

    for (long long neighbor : adj[nd]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}