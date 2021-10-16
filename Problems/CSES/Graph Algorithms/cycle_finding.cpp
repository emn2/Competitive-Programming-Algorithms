#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
struct Edge {
    ll a, b, cost;
};
 
int n, m;
vector<Edge> edges;
const ll INF = 1e9 + 5;
 
void solve(){
    vector<ll> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
 
    if (x == -1) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];
 
        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
 
        cout << "YES\n";
        for (int v : cycle)
            cout << v+1 << ' ';
        cout << endl;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    edges.resize(m);
 
    ll u, v, custo;
 
    for(int i = 0; i < m; i++){
        cin >> u >> v >> custo;
        u--, v--;
        edges[i].a = u;
        edges[i].b = v;
        edges[i].cost = custo;
    }
 
    solve();
 
    return 0;
}
