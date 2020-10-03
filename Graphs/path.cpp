#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;

    vector<int> nodes (n+1);
    vector<vector<int> > adj (n+1);
    vector<bool> visited (n+1, false);
    queue<int> q;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int start, end;
    cin >> start >> end;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(current == end) ans = 1;

        for(auto e: adj[current]){
            if(visited[e] == false){
                visited[e] = true;
                q.push(e);
            }
            else {
                ans = 1;
            }
        }
    }

    if(ans == 1) cout << "Yes\n";
    else  cout << "No\n";

    return 0;
}
