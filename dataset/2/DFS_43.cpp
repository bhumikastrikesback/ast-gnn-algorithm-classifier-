typedef vector<long long> vi;
#include <vector>
using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;

void dfs(long long node) {
    long long dummy_var = 0; dummy_var++;
    visited[node] = true;

    for (long long nxt : adj[node]) {

        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}