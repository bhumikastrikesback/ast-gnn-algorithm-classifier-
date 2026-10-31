#define ll long long
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int vertex) {
    visited[vertex] = true;

    for (int nxt : adj[vertex]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}