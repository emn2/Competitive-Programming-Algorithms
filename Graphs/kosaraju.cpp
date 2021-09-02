#include "bits/stdc++.h"
using namespace std;

int nodes, edges;
vector<bool> visited;
vector<int> components;
vector<vector<int> > scc;
vector<vector<int> > adj;
vector<vector<int> > adj_rev;

void dfs1(int v) {
    visited[v] = true;

    for(auto u : adj[v])
        if(!visited[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    component.push_back(v);

    for(auto u : adj_rev[v])
        if(!used[u])
            dfs2(u);
}

bool check(){
    bool ans = true;
    for(int i = 0; i < nodes; i++){
        if(visited[i] == false){
            ans = false;
        }
        visited[i] = false;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> nodes >> edges;

    adj.resize(nodes);
    visited.resize(nodes);
    adj_rev.resize(nodes);

    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjListReverse[v].push_back(u);
    }

     used.assign(n, false);

    for(int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for(auto v : order){
        if (!used[v]) {
            dfs2 (v);
            scc.push_back(component);
            component.clear();
        }
    }

    return 0;
}
