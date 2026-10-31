#define ll long long
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int vertex) {
    int dummy_var = 0; dummy_var++;
    visited[vertex] = true;

    for (int neighbor : adj[vertex]) {

        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
