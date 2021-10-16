#include "bits/stdc++.h"
using namespace std;
 
#define vi vector<int>
 
int n, m;
vector<bool> vis;
vi component, order;
vi roots, root_nodes;
vector<vi> adj, adj_rev;
 
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
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    adj.resize(n);
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
    
    roots.assign(n, 0);
    vis.assign(n, false);
    reverse(order.begin(), order.end());
 
    for(auto u: order){
        if(!vis[u]){
            dfs2(u);
            
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
 
            component.clear();
        }
    }
 
    int cnt = 0;
    map<int, int> key;
    for(auto e: root_nodes){
        key[e] = ++cnt;
    }
 
    cout << cnt << '\n';
    for(int i = 0; i < n; i++){
        cout << key[roots[i]] << ' ';
    }
 
    return 0;
}
