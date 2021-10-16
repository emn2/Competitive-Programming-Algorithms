#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
typedef long long ll;
 
int n, m;
vector<bool> vis;
vector<ll> dp, rew;
vi component, order;
vi root_nodes, roots;
vector<vi> adj, adj_rev, scc;
 
void dfs1(int u){
    vis[u] = true;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    order.push_back(u);
}
 
void dfs2(int u){
    vis[u] = true;
    component.push_back(u);
 
    for(auto v: adj_rev[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}
 
ll solve(int i){
    if(dp[i]) return dp[i];
 
    dp[i] = rew[i];
    for(auto j: scc[i]){
        dp[i] = max(dp[i], solve(j) + rew[i]);
    }
    return dp[i];
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
 
    adj.resize(n);
    rew.resize(n, 0);
    adj_rev.resize(n);
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
 
    vis.assign(n, false);
 
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
 
    vis.assign(n, false);
    reverse(order.begin(), order.end());
 
    scc.resize(n);
    roots.assign(n, 0);
 
    for(auto u: order){
        if(!vis[u]){
            dfs2(u);
            
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
 
            component.clear();
        }
    }
 
    for (int v = 0; v < n; v++){
        for (auto u : adj[v]) {
            int root_v = roots[v], root_u = roots[u];
 
            if(root_u != root_v)
                scc[root_v].push_back(root_u);
        }
    }
 
    for(int i = 0; i < n; i++)
        rew[roots[i]] += p[i];
 
    ll ans = 0;
    int n_new = scc.size();
    
    dp.assign(n, 0);
    
    for(int i = 0; i < n_new; i++){
        ans = max(ans, solve(i));
    }
 
    cout << ans << '\n';
 
    return 0;
}
