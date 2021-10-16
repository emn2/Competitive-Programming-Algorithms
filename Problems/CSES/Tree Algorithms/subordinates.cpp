#include "bits/stdc++.h"
using namespace std;
const int maxn = 2e5 + 5;
 
int sub[maxn] = {};
vector<vector<int> > adj;
 
void dfs(int u){
    for(auto v: adj[u]){
        dfs(v);
        sub[u] += sub[v] + 1;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
 
    adj.resize(n+1);
 
    for(int i = 2; i <= n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
 
    dfs(1);
 
    for(int i = 1; i <= n; i++)
        cout << sub[i] << ' ';
 
    return 0;   
}
