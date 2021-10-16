#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
const ll INF = 1e18 + 5;
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<ii> > adj(n+5);
    for(int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].pb(mp(d, v));
    }
    vector<ll> dist(n+5, INF);
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(mp(0, 1));
    dist[1] = 0;
    while(!pq.empty()){
        pll cur = pq.top();
        pq.pop();
        if(dist[cur.y] < cur.x) continue;
        for(auto e: adj[cur.y]){
            int v = e.y;
            if(dist[cur.y] + e.x < dist[v]){
                dist[v] = dist[cur.y] + e.x;
                pq.push(mp(dist[v], v));
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dist[i] << ' ';
}
