#include <bits/stdc++.h>
using namespace std;
 
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
const int inf = 0x3f3f3f3f;
 
vector<vector<ii>> adjList;
map<int,map<int,int>> peso;
 
void BellmanFord(int source,int V,int E){
    map<int,map<int,int>> dist;
    map<int,int> prec;
    forc(i,V){
        dist[0][i] = inf;
        prec[i] = -1;
    }
    dist[0][source] = 0;
    for(int k=1;k<V;k++){
        dist[k] = dist[k-1];
        for(int u=0;u<V;u++){
            for(auto graf:adjList[u]){
                int v = graf.first;
                int w = graf.second;
                if(dist[k][v] > dist[k-1][u] + w){
                    dist[k][v] = dist[k-1][u] + w;
                    prec[v] = u;
                }
            }
        }
    }
    dist[V] = dist[V-1];
    for(int u=0;u<V;u++){
        for(auto graf:adjList[u]){
            int v = graf.first;
            int w = graf.second;
            if(dist[V][v] > dist[V-1][u] + w){
                cout << "Erro, ciclo negativo" << endl;
                return;
            }
        }
    }
    forc(i,V){
        printf("Dist de %d ate %d é %d\n",source,i,dist[V-1][i]);
        if(dist[V-1][i] > 0 && dist[V-1][i] < inf-10){
            printf("Caminho até %d:\n",i);
            int temp = i;
            vector<ii> caminho;
            while(temp != source){
                caminho.pb(mp(temp,peso[temp][prec[temp]]));
                temp = prec[temp];
            }
            printf("%d --> ",source);
            int n = caminho.size();
            for(int j=0;j<n -1;j++){
                printf("w = %d --> %d --> ",caminho[j].second,caminho[j].first);
            }
            printf("w = %d --> %d\n",caminho[n-1].second,caminho[n-1].first);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        adjList.clear();
        peso.clear();
        int V,E; cin >> V >> E;
        adjList.resize(V);
        forc(i,E){
            int u,v,w; cin >> u >> v >> w;
            adjList[u].pb(mp(v,w));
            peso[u][v] = w;
            peso[v][u] = w;
        }
        for(int source = 0;source<V;source++){
            BellmanFord(source,V,E);
        }
    }
    return 0;
}
