#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef pair<int, int> ii;
const int INF = 1e18 + 5;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    queue<int> queima;
    vector<int> temp(n+1);
    vector<vector<ii> > adj(n+1);
    vector<int> dist(n+1, INF);

    priority_queue<ii, vector<ii>, greater<ii> > pq;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    for(int i = 1; i <= n; i++)
        cin >> temp[i];
    
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        dist[a] = temp[a];
        pq.push(make_pair(a, dist[a]));
    }

    
    while(!pq.empty()){
        ii atual = pq.top();
        pq.pop();

        if(dist[atual.first] < atual.second) continue;

        for(auto e: adj[atual.first]){
            int v = e.first;
            int w = e.second + temp[v];

            if(dist[atual.first] + w < dist[v]){
                dist[v] = dist[atual.first] + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    

    for(int i = 1; i <= n; i++)
        cout << dist[i] << '\n';

    return 0;
}
