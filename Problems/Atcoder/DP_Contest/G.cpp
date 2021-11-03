#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;

int n, m, dp[MAXN];
vector<int> adj[MAXN];

int dfs(int u){
    if(adj[u].size() == 0) return 0;

    if(~dp[u]) return dp[u];

    int ans = 0;
    for(auto v: adj[u])
        ans = max(ans, 1 + dfs(v));

    return dp[u] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) dfs(i);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans << '\n';
}
