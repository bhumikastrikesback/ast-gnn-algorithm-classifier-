typedef vector<long long> vi;
#include <vector>
using namespace std;

vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long nd) {
    long long dummy_var = 0; dummy_var++;
    visited[nd] = true;

    for (long long neighbor : adj[nd]) {

        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}