#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;
 
int n, m;
vector<vector<int> > capacity;
vector<vector<int> > adj;
 
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q;
    q.push(make_pair(s, INF));
 
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
 
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push(make_pair(next, new_flow));
            }
        }
    }
 
    return 0;
}
 
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+m+5);
    int new_flow;
 
    while (new_flow = bfs(s, t, parent)) {
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
 
//source -> 0, boys -> 1 to n, girls -> n + 1 to n + m , sink -> n + m + 1
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int k;
    cin >> n >> m >> k;
 
    capacity.assign(n+m+5, vector<int>(n+m+5, 0));
    adj.resize(n+m+5);
 
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v+n);
        adj[v+n].push_back(u);
        capacity[u][v+n] = 1;
    }
 
    for(int i = 1; i <= n; i++){
        adj[0].push_back(i);
        adj[i].push_back(0);
        capacity[0][i] = 1;
    }
 
    for(int i = n+1; i <= n+m; i++){
        adj[i].push_back(n+m+1);
        adj[n+m+1].push_back(i);
        capacity[i][n+m+1] = 1;
    }
 
    cout << maxflow(0, n+m+1) << '\n';
 
    for(int i = 1; i <= n; i++){
        if(capacity[0][i] == 0){
            for(auto e: adj[i]){
                if(capacity[i][e] == 0){
                    cout << i << ' ' << e-n << '\n';
                    break;
                }
            }
        }
    }
 
    return 0;
}
