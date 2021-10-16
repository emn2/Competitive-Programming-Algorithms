#include "bits/stdc++.h"
using namespace std;
 
int nodes, a = 1, b;
vector<bool> visited;
vector<vector<int> > adjList;
vector<vector<int> > adjListReverse;
 
void dfs(int u, vector<vector<int> >& list){
    if(visited[u]) return;
    visited[u] = true;
 
    for(int i = 0; i < list[u].size(); i++){
        int v = list[u][i];
        dfs(v, list);
    }
}
 
bool check(){
    bool ans = true;
    for(int i = 0; i < nodes; i++){
        if(visited[i] == false){
            ans = false;
            b = i + 1;
        }
        visited[i] = false;
    }
    return ans;
}
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int edges;
    cin >> nodes >> edges;
 
    adjList.resize(nodes);
    visited.resize(nodes);
    adjListReverse.resize(nodes);
 
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adjList[u].push_back(v);
        adjListReverse[v].push_back(u);
    }
 
    dfs(0, adjList);
 
    if(check() == false){
        cout << "NO\n";
        cout << a << ' ' << b << '\n';  
        return 0;
    }
 
    dfs(0, adjListReverse);
 
    if(check() == false){
        cout << "NO\n";
        cout << b << ' ' << a << '\n';  
    }
    else{
        cout << "YES\n";
    } 
 
    return 0;
}
