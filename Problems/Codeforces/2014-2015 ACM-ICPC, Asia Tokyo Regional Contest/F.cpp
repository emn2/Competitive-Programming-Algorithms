#include "bits/stdc++.h"
using namespace std;
const int LIM = 505;
typedef pair<int, pair<int, int> >ii;

int nodes, m, peso_total;
int root[LIM], sz[LIM];
vector<int> used;
vector<ii> adj_original;

int cnt = 0, sum = 0;

int find(int a){
    if(root[a] == a) return a;
    return root[a] = find(root[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b]) root[b] = a;        
        else root[a] = b;
        sz[b] += sz[a];
        sz[a] = sz[b];
    }
}

void kruskal(int j){
    int mst_w = 0, qnt = 0;

    for(int i = 0; i < LIM; i++){
        root[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < adj_original.size(); i++){
        if(i != j){
            ii e = adj_original[i];
            if(find(e.second.first) != find(e.second.second)){
                join(e.second.first, e.second.second);
                mst_w += e.first;
                qnt++;
                if(j == -1) used.push_back(i);
            }
            if(qnt == nodes - 1) break;
        }
    }

    if(j == -1){
        peso_total = mst_w;
    }

    if(peso_total != mst_w && j != -1){
        cnt++;
        sum += adj_original[j].first;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> nodes >> m;
    adj_original.resize(m);
    for(int i = 0; i < m; i++){
        cin >> adj_original[i].second.first >> adj_original[i].second.second >> adj_original[i].first;
    }

    sort(adj_original.begin(), adj_original.end());

    kruskal(-1);

    for(auto e: used){
        kruskal(e);
    }
    
    cout << cnt << ' ' << sum << '\n';

    return 0;
}
