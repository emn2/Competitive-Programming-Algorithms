#include "bits/stdc++.h"
using namespace std;

int nodes;
vector<bool> visited;
vector<int> components;
vector<vector<int> > scc;
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
        }
        visited[i] = false;
    }
    return ans;
}

int main(){
    int edges;
    cin >> nodes >> edges;

    adjList.resize(nodes);
    visited.resize(nodes);
    adjListReverse.resize(nodes);

    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjListReverse[v].push_back(u);
    }

    dfs(0, adjList);

    if(check() == false){
        cout << "No\n";
        return 0;
    }

    dfs(0, adjListReverse);

    if(check() == false)
        cout << "No\n";
    else 
        cout << "Yes\n";

    return 0;
}
