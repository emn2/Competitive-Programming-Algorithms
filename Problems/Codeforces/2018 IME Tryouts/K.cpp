#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ii, int> iii;
typedef pair<ll, pll> plll;
const int LIM = 1e5 + 50;
const ll INF = 1e18 + 5;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define grafo vector<vector<id> >
#define forc(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n-1); i >= 0; i--)

bool vis[LIM][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(vis, false, sizeof(vis));

    int n, m;
    cin >> n >> m;
    vector<vector<pll> > valor(n+1);
    for(int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        valor[u].push_back(mp(v, w));
        valor[v].push_back(mp(u, w));
    }
    
    //dist, no atual, num roads
    //pair<ll, pair<ll, ll>> pll 
  
    priority_queue<plll, vector<plll>, greater<plll> > pq;
    vector<vector<ll> > dist(LIM);
    for(int i = 0; i < LIM; i++) dist[i].assign(3, INF);
    pq.push(mp(0, mp(1, 0)));
    dist[1][0] = 0;

    while(!pq.empty()){
        ll d = pq.top().x;
        ll u = pq.top().y.x;
        ll r = pq.top().y.y;
        pq.pop();
        if(u == n) continue;
        vis[u][r] = true;
        for(auto e: valor[u]){
            ll w = e.y, v = e.x;
            if(!vis[v][(r+1)%3] && (dist[u][r] + w < dist[v][(r+1)%3])){
                dist[v][(r+1)%3] = dist[u][r] + w;
                pq.push(mp(dist[v][(r+1)%3],mp(v, ((r+1)%3))));
            }
        }
    }

    vector<pair<ll, string> > ans;
    ans.push_back(mp(dist[n][0], "me"));
    ans.push_back(mp(dist[n][1], "Gon"));
    ans.push_back(mp(dist[n][2], "Killua"));
    sort(ans.begin(), ans.end());
    for(auto e: ans) cout << e.y << '\n';

    return 0;
}
