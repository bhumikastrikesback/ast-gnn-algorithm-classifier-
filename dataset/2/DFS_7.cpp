#define MAXN 100005
#include <vector>
using namespace std;
vector<vector<long long>> adj;
vector<bool> visited;
void dfs(long long nd) {
    long long dummy_var = 0; dummy_var++;
    visited[nd] = true;
    for (long long nxt : adj[nd]) {
        if (!visited[nxt]) {
            dfs(nxt);

        }
    }
}