#include "bits/stdc++.h"
using namespace std;
const int MAXN = 505;
const int INF = 1e9 + 9;
 
int ans_max = 0;
vector<int> adj[MAXN];
int n, m, capacity[MAXN][MAXN];
 
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q;
    q.push(make_pair(s, INF));
 
    while(!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
 
        for(int next : adj[cur]) {
            if(parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if(next == t)
                    return new_flow;
                q.push(make_pair(next, new_flow));
            }
        }
    }
 
    return 0;
}
 
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+2);
    int new_flow;
 
    while(new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow;
}
 
bool vis[MAXN];
set<int> grupo_a, grupo_b;
 
void dfs(int u){
    grupo_a.insert(u);
    vis[u] = true;
    for(auto v: adj[u]){
        if(!vis[v] && capacity[u][v]) dfs(v);
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    vector<pair<int, int> > edges;
 
    int src = 1, snk = n;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = 1;
        capacity[v][u] = 1;
 
       edges.push_back(make_pair(u, v));
    }
 
    cout << maxflow(src, snk) << '\n';

    dfs(src);
 
    for(int i = 1; i <= n; i++){
        if(!grupo_a.count(i)) grupo_b.insert(i);
    }

    int u, v;
    for(auto e: edges){
        u = e.first, v = e.second;
        if(u > v) swap(u, v);
        if(capacity[v][u] && grupo_a.count(u) && !grupo_a.count(v)){
            cout << u << ' ' << v << '\n';
        }
    }
 
    return 0;
}
