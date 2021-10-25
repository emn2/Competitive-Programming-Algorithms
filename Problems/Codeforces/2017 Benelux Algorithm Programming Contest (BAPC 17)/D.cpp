#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ii, int> iii;
typedef pair<ll, pll> plll;
const int MOD = 1e9;
const int LIM = 1e6 + 5;
const ll INF = 1e18 + 5;
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define grafo vector<vector<ii> >
#define forc(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n-1); i >= 0; i--)

grafo adj;
vector<ll> dist;
vector<bool> vis;
vector<int> caminho;
bool encontrei = false;
ll estaCaminho[LIM];

void dfs(int u){
    if(u == 1) {
        encontrei = true;
        return;
    }
    for(auto e: adj[u]){
        int v = e.y, w = e.x;
        if(dist[u] == dist[v] + w) continue;    //menor caminho
        if(!vis[v]){
            vis[v] = true;
            estaCaminho[u] = v; 
            dfs(v);
        }
        if(encontrei) return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    memset(estaCaminho, -1, sizeof(estaCaminho));

    adj.resize(n+5);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(mp(w, v));
        adj[v].pb(mp(w, u));
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist.assign(n+5, INF);
    dist[1] = 0;
    pq.push(mp(0, 1));

    while(!pq.empty()){
        ii cur = pq.top();
        pq.pop();
        ll w = cur.x, u = cur.y;

        if(w > dist[u]) continue;

        for(auto e: adj[u]){
            ll ww = e.x, v = e.y;
            if(dist[u] + ww < dist[v]){
                dist[v] = dist[u] + ww;
                pq.push(mp(dist[v], v));
            }
        }
    }

    vis.assign(n+5, false);
    vis[0] = 1;
    dfs(0);

    if(encontrei) {
        int atual = 0;
        while(atual != -1){
            caminho.pb(atual);
            atual = estaCaminho[atual];
        }
        cout << caminho.size();
        for(auto &a: caminho) cout << ' ' << a;
    }
    else cout << "impossible\n";

    return 0;
}
