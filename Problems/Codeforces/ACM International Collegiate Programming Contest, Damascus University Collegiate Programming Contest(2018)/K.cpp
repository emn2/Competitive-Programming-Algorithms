#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef long double ld;

const ll INF = 1e15;
const int ms = 1e5 + 2, mlg = 18;
int n, q;
int par[ms][mlg+1], lvl[ms];
ll dw[ms];
vector<pii> g[ms];

void dfs(int v, int p, int l = 0, ll w = 0) {
    lvl[v] = l;
    dw[v] = w;
    par[v][0] = p;
    for (int k = 1; k <= mlg; k++) {
        par[v][k] = par[par[v][k-1]][k-1];
    }
    for (auto u : g[v]) {
        if (u.S != p) dfs(u.S,v,l+1,w+u.F);
    }
}

int lca(int a, int b) {
    if (lvl[b] > lvl[a]) swap(a,b);
    for (int i = mlg; i >= 0; i--) {
        if (lvl[a] - (1 << i) >= lvl[b]) a = par[a][i];
    }
    if (a == b) return a;
    for (int i = mlg; i >= 0; i--) {
        if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    }
    return par[a][0];
}

ll dist(int a, int b) {
    return dw[a] + dw[b] - 2*dw[lca(a,b)];
}

vector<ll> dij(int org) {
    vector<ll> d(n,INF);
    d[org] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,org});
    while (pq.size()) {
        pll next = pq.top(); pq.pop();
        ll w = next.F, u = next.S;
        if (w > d[u]) continue;
        for (auto v : g[u]) {
            if (d[u] + v.F < d[v.S]) {
                d[v.S] = d[u] + v.F;
                pq.push({d[v.S],v.S});
            }
        }
    }
    return d;
}

ll su = -1, sv = -1, sw = 0;

int cy[ms];
void dfs1(int u, int p) {
    cy[u] = 1;
    for (auto e : g[u]) {
        if (cy[e.S] == 1 && e.S != p && su == -1) {
            su = u, sv = e.S, sw = e.F;
        }
        if (cy[e.S] == 0) dfs1(e.S,u);
    }
    cy[u] = 2;
}

vector<ll> d1, d2;

int main () {    
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        memset(cy,0,sizeof cy);
        su = -1, sv = -1, sw = 0;
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            int u,v,w; cin >> u >> v >> w; u--, v--;
            g[u].push_back({w,v});
            g[v].push_back({w,u});
        }
        dfs1(0,0);
        auto it1 = find(g[su].begin(),g[su].end(),pii(sw,sv));
        assert(it1 != g[su].end());
        g[su].erase(it1);
        auto it2 = find(g[sv].begin(),g[sv].end(),pii(sw,su));
        assert(it2 != g[sv].end());
        g[sv].erase(it2);
        dfs(0,0);
        d1 = dij(su), d2 = dij(sv);
        while (q--) {
            int x,y; cin >> x >> y; x--, y--;
            ll dmn = min(sw+d1[x]+d2[y],sw+d1[y]+d2[x]);
            ll ans = min(dist(x,y), dmn);
            cout << ans << endl;
        }
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
    }
    return 0;
}
