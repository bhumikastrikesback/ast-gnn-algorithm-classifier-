#define pb push_back
#include <vector>
using namespace std;
vector<vector<int>> adj;

vector<bool> visited;
void dfs(int nd) {
    visited[nd] = true;
    for (int nxt : adj[nd]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}