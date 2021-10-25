#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll INF = 1e18 + 5;

int n, m, q;

deque<int> ans;
vector<vector<ii> > adj;

void dijkstra(int s, int looking){
    vector<ll> dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    dist[s] = 0;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        int x = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u] < x) continue;
        
        for(auto e: adj[u]){
            int v = e.first;
            int w = e.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if(dist[looking] == INF) ans.push_front(-1);
    else ans.push_front(dist[looking]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    adj.resize(n+5);
    map<ii, int> weight;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        weight[make_pair(u, v)] = w;
        weight[make_pair(v, u)] = w;
    }

    deque<iii> dq;

    for(int i = 0; i < q; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dq.push_front(make_pair(make_pair(u, v), w));
    }

    while(!dq.empty()){
        int op = dq.front().first.first;
        int u = dq.front().first.second;
        int v = dq.front().second;

        dq.pop_front();

        if(op == 0){
            int w = weight[make_pair(u, v)];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        else{
            dijkstra(u, v);
        }
    }

    while(!ans.empty()){
        int cur = ans.front();
        ans.pop_front();

        if(cur == -1) cout << "IMPOSSIBLE\n";
        else cout << cur << '\n';
    }
    
    
    return 0;
}
