#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int LIM = 505;
const ll INF = 1e18 + 5;
#define min(a, b) ((a < b) ? a : b)
 
ll dist[LIM][LIM];
 
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
 
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
 
    for(int k = 0; k <= n; k++)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        if(dist[u][v] == INF) cout << "-1\n";
        else cout << dist[u][v] << '\n';
    }
}
