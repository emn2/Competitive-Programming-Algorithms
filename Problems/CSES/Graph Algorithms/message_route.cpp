#include "bits/stdc++.h"
using namespace std;
 
const int INF = 1e9;
 
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define grafo vector<vector<int> >
#define spid ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main(){
    spid;
    int n, m;
    cin >> n >> m;
    grafo adj(n+5);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> dist(n+5, INF);
    vector<int> par(n+5, -1);
 
    pq.push(1);
    dist[1] = 1;
 
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        for(auto e: adj[cur]){
            if(dist[cur] + 1 < dist[e]){
                pq.push(e);
                par[e] = cur;
                dist[e] = dist[cur] + 1;
            }
        }
    }
 
    if(dist[n] == INF) cout << "IMPOSSIBLE\n";
    else {
        cout << dist[n] << '\n';
        int i = n;
        vector<int> ans;
        ans.pb(n);
        while(par[i] != -1){
            i = par[i];
            ans.pb(i);
        }
        for(int i = ans.size()-1; i >= 0; i--)
            cout << ans[i] << ' ';
        cout << '\n';
    }
 
    return 0;
}
