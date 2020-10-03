#include "bits/stdc++.h"
using namespace std;

int main(){
    int nv, na; //vertices e arestas
    cin >> nv >> na;

    vector<vector<int> > adj(nv);
    vector<int> dependencias(nv, 0);
    vector<int> ordem;
    queue<int> q;

    int a, b;

    while(na--){
        cin >> a >> b;
        adj[a].push_back(b);
        dependencias[b]++;
    }

    for(int i = 0; i < nv; i++){
        if(dependencias[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int current = q.front();
        q.pop();

        ordem.push_back(current);

        for(int to: adj[current]){
            dependencias[to]--;
            if(dependencias[to] == 0) q.push(to);
        }
    }

    for(int i = 0; i < ordem.size(); i++){
        cout << ordem[i] << " ";
    }

    cout << '\n';

    return 0;
}