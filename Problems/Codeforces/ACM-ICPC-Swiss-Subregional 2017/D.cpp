#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int n;
ll dist_max;
vector<vector<int> > adj;

ll bfs(int i){
    queue<int> q;
    q.push(i);
    ll dist_max_agora = 0LL;
    vector<ll> dist(n, INF);
    vector<bool> vis(n, false);

    vis[i] = true;
    dist[i] = 0LL;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = true;
                dist[v] = dist[u] + 1;
                dist_max_agora = max(dist_max_agora, dist[v]);
                q.push(v);
            }
        }
    }

    return dist_max_agora;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, k;
    cin >> n >> m >> k;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist_max = 0LL;
    for(int i = 0; i < n; i++){
        dist_max = max(dist_max, bfs(i));
    }
    
    if(dist_max > n - k) cout << "0\n";
    else{
        cout << n << '\n';
        for(int i = 1; i <= n; i++) cout << i << ' ';
    }

    return 0;
}
