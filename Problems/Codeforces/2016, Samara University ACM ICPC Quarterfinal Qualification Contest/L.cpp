#include "bits/stdc++.h"
using namespace std;

int n;

void bfs(int u, vector<vector<int> >&graph, vector<int>& dist){
    queue<int> q;
    q.push(u);
    vector<bool> visited(n+2, false);
    visited[u] = true;
    dist[u] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto e: graph[cur]){
            if(!visited[e]){
                visited[e] = true;
                dist[e] = dist[cur] + 1;
                q.push(e);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> dep(n+1, 0);
    vector<vector<int> > adj(n+1);
    vector<vector<int> > adjReverse(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjReverse[v].push_back(u);
        dep[v]++;
    }

    for(int i = 1; i <= n; i++){
        if(dep[i] == 0) {
            adj[0].push_back(i);
            adjReverse[i].push_back(0);
        }
    }

    vector<int> distZero(n+5, 1e9), distA(n+5, 1e9), distB(n+5, 1e9);

    bfs(0, adj, distZero);
    bfs(a, adjReverse, distA);
    bfs(b, adjReverse, distB);

    int ans = 1e9;
    for(int i = 0; i <= n; i++){
        ans = min(ans, distA[i] + distB[i] + distZero[i]);
    }

    cout << ans << '\n';

    return 0;
}
