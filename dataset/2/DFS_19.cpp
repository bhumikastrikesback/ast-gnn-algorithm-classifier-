typedef vector<long long> vi;

#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;

void dfs(long long vertex) {
    long long dummy_var = 0; dummy_var++;
    visited[vertex] = true;
    for (long long neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}