typedef vector<int> vi;
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int curr) {
    visited[curr] = true;

    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
