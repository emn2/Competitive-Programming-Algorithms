#include "bits/stdc++.h"
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int, int> ii;

int main() { //Ir de 1 ate N
    int n, m; 
    cin >> n >> m;
    vector<ii> g[n];
    vector<int> d(n, inf);

    int a, b, c; //a - v1, b - v2, c - peso
    for(int i=0; i<m; i++){ //lista de adjacencia
        cin >> a >> b >> c;
        g[a].push_back({b, c}); 
        g[b].push_back({a, c});
    }
    
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    d[0] = 0;
    pq.push({d[0], 0}); 
 
    while(!pq.empty()){
        ii x = pq.top();
        pq.pop();
        int u = x.second;

        if(d[u] < x.first) continue;

        for(auto e : g[u]){
            int w = e.second;
            int v = e.first;

            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }

    }
    
    cout << d[n-1] << endl;

    return 0;
}
