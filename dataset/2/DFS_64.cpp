#define ll long long
#include <vector>
using namespace std;
vector<vector<long long>> adj;

vector<bool> visited;
void dfs(long long curr) {
    visited[curr] = true;
    for (long long neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }

}