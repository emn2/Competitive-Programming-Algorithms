#include "bits/stdc++.h"
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> dep(n+5, 0);
    vector<vector<int> > adj(n+5);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dep[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    vector<int> ans;
    vector<bool> vis(n+5, false);
    for(int i = 1; i <= n; i++){
        if(dep[i] == 0){
            q.push(i);
            vis[i] = true;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto e: adj[cur]){
            dep[e]--;
            if(dep[e] <= 0 && !vis[e]){
                vis[e] = true;
                q.push(e);
            }
        }
    }
    if(ans.size() != n) cout << "IMPOSSIBLE\n";
    else{
        for(auto e: ans) cout << e << ' ';
    }
    return 0;
}
