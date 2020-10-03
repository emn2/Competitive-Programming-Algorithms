//Detecting Cycles in a Directed Graph using DFS

#include "bits/stdc++.h"
using namespace std;

int n, nCycles = 0; //n = number of nodes
vector<vector<int> > adjList;
vector<bool> visited;
vector<bool> recStack;

void dfs(int u){
    if(recStack[u]) nCycles++;
    if(visited[u]) return;

    visited[u] = true;
    recStack[u] = true;

    for(int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        dfs(v);
    }
}

int main(){
    int u, v, start;    
    cin >> n >> start;

    adjList.resize(n);
    visited.resize(n);
    recStack.resize(n);

    while(cin >> u >> v){
        adjList[u].push_back(v);
    }

    dfs(start);

    cout << nCycles << '\n';

    return 0;
}
