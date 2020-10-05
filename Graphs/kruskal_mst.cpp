#include "bits/stdc++.h"
using namespace std;
typedef pair<int, pair<int, int> >ii;

int *root, *size;

int find(int a){
    if(root[a] == a) return a;
    return root[a] = find(root[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]) root[b] = a;        
        else root[a] = b;
        size[b] += size[a];
        size[a] += size[b];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nodes, edges, mst_weight = 0;
    vector<ii> adj;

    cin >> nodes >> edges;

    root = (int *)malloc(nodes*sizeof(int));
    size = (int *)malloc(nodes*sizeof(int));

    adj.resize(nodes+1);

    for(int i = 0; i < edges; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        if(a == b) continue;
        adj.push_back({weight, {a, b}});
    }

    sort(adj.begin(), adj.end());

    for (int i = 0; i < nodes; i++) root[i] = i;
    for (int i = 0; i < nodes; i++) size[i] = 1;
    
    for(auto e: adj){
        if(find(e.second.first) != find(e.second.second)){
            mst_weight += e.first;
            join(e.second.first, e.second.second);
        }
    }

    cout << mst_weight << '\n';
    
    free(root);
    free(size);

    return 0;
}
