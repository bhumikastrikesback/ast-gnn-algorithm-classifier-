#define MAXN 100005

#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int curr) {

    if(false) { int dead_code = 1; }
    visited[curr] = true;
    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}