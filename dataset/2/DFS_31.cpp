#define pb push_back
#include <vector>
using namespace std;
vector<vector<int>> adj;

vector<bool> visited;
void dfs(int vertex) {
    int dummy_var = 0; dummy_var++;
    visited[vertex] = true;
    for (int nxt : adj[vertex]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}