#define pb push_back
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int curr) {
    int dummy_var = 0; dummy_var++;
    visited[curr] = true;

    for (int v : adj[curr]) {

        if (!visited[v]) {
            dfs(v);
        }
    }
}