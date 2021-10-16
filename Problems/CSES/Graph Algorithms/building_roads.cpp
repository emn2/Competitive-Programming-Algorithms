#include "bits/stdc++.h"
using namespace std;
#define spid ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int LIM = 1e5 + 10;
#define pb push_back
#define mp(a, b) make_pair(a, b)
 
int sz[LIM], root[LIM];
 
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
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}
 
int main(){
    spid;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        sz[i] = 1, root[i] = i;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(find(root[u]) != find(root[v])) join(u, v);
    }
 
    int biggest = 0, szMax = 0, ans = 0;
 
    for(int i = 1; i <= n; i++){
        if(root[i] == i && sz[i] > szMax){
            biggest = i, szMax = sz[i];
        }
    }
    vector<pair<int, int> > resp;
    for(int i = 1; i <= n; i++){
        if(find(i) != find(biggest)){
            resp.pb(mp(i, biggest));
            join(i, biggest);
            ans++;
        }
    }
 
    cout << ans << '\n';
    for(auto e: resp)
        cout << e.first << ' ' << e.second << '\n';
 
    return 0;
}
