#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

void fatorar(vector<int> &divisores, int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            divisores.push_back(i);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1) divisores.push_back(n);
}

vector<bool> vis;
vector<ll> depth;
vector<vector<int> > adj;

int dfs(int u){
    if(vis[u]) return depth[u];

    vis[u] = true;

    int ans = 1;

    for(auto v: adj[u]){
        ans = max(ans, 1 + dfs(v));
    }
    return depth[u] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> divisores;
    vector<int> ultima_pos(MAXN, -1);

    adj.resize(n);

    for(int i = n-1; i >= 0; i--){
        fatorar(divisores, a[i]);
        for(auto e: divisores){
            if(ultima_pos[e] != -1){
                adj[i].push_back(ultima_pos[e]);
            }
            ultima_pos[e] = i;
        }
        divisores.clear();
    }   

    depth.resize(MAXN, 0);
    vis.assign(MAXN, false);

    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i);
    }

    ll resp = 0;
    for(int i = 0; i < n; i++) resp = max(resp, depth[i]);
    
    cout << resp << '\n';

    return 0;
}
