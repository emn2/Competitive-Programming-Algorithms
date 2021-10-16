#include "bits/stdc++.h"
using namespace std;
#define pb push_back
 
vector<bool> visit;
vector<bool> color;
vector<vector<int> > adj;
 
bool isBipartite(int v){ 
    for (int u : adj[v]) { 
        if (visit[u] == false) { 
            visit[u] = true; 
            color[u] = !color[v]; 
  
            if(!isBipartite(u)) return false; 
        } 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 
 
int main(){
    int n, m;
    cin >> n >> m;
 
    visit.resize(n+5, false);
    color.resize(n+5, true);
    adj.resize(n+5);
 
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool ans = true;
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            visit[i] = true;
            color[i] = false;
            ans = isBipartite(i);
        }
    }
 
 
    if(ans){
        for(int i = 1; i <= n; i++){
            if(color[i]) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
    }
    else cout << "IMPOSSIBLE\n";
 
}
