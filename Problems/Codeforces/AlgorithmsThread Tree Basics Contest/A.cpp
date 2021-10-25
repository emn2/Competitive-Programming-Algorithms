#include "bits/stdc++.h"
using namespace std;

vector<int> dist;
vector<vector<int> > adj;

void dfs(int u, int p, int d = 0){
    dist[u] = d;
    for(auto v: adj[u]){
        if(v != p) dfs(v, u, d+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, ans = 0, maior = 0;
    cin >> n;

    adj.resize(n+1);

    dist.assign(n+1, 0);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    for(int i = 1; i <= n; i++){
        if(dist[i] > dist[maior]) maior = i;
    }

    dist.assign(n+1, 0);

    dfs(maior, maior);

    for(int i = 1; i <= n; i++)
        ans = max(ans, dist[i]);
    
    cout << 3*ans << '\n';

    return 0;
}
