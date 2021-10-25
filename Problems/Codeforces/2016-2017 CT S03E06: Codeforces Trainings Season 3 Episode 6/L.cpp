#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef pair<ll, double> id;
typedef pair<double, ll> di;
typedef pair<ii, double> iid;
const int LIM = 1e5;
const double INF = 1e18 + 5;
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define grafo vector<vector<id> >
#define forc(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n-1); i >= 0; i--)

double dist(ii p1, ii p2){
    double dx = p1.x-p2.x;
    double dy = p1.y-p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    ii start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    cin.ignore();
    vector<iid> nos(LIM);

    nos[0] = mp(mp(start.x, start.y), 0);
    nos[1] = mp(mp(end.x, end.y), 1);

    string s;
    int qntd = 2, qualNo = 2;
    while(getline(cin, s)){
        ll i, j;
        stringstream ss(s);
        while(ss >> i >> j){
            if(i == -1 && j == -1) qualNo++;
            else nos[qntd++] = mp(mp(i, j), qualNo);
        }
    }

    //Velocidadas: Andando e de Metro
    double v1 = 1000.0/6.0, v2 = 4000.0/6.0;

    grafo adj(LIM);
    for(int i = 0; i < qntd; i++){
        for(int j = i+1; j < qntd; j++){
            if(i == j) continue;
            double d = dist(nos[i].x, nos[j].x);
            if(nos[i].y == nos[j].y && j == i+1) d /= v2;
            else d /= v1;
            adj[i].pb(mp(j, d));
            adj[j].pb(mp(i, d));
        }
    }
    vector<double> dist(LIM, INF);
    priority_queue<di, vector<di>, greater<di> > pq;
    dist[0] = 0;
    pq.push(mp(0, 0));
    while(!pq.empty()){
        int u = pq.top().y;
        double d = pq.top().x;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto e: adj[u]){
            int v = e.x;
            double w = e.y;
            if(w + dist[u] < dist[v]){
                dist[v] = w + dist[u];
                pq.push(mp(dist[v], v));
            }
        }
    }
    cout << fixed << setprecision(0) << round(dist[1]) << '\n';
    return 0;
}
