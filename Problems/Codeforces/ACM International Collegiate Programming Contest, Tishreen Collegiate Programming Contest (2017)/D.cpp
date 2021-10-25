#include "bits/stdc++.h"
using namespace std;

int saoAmigos[20];

int numOn(int mask, int n){
    int resp = 0;
    for(int i = 0; i < n; i++)
        if(mask & (1 << i)) resp++;
    return resp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        memset(saoAmigos, 0, sizeof(saoAmigos));
        int p, n;
        cin >> p >> n;
        for(int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;                   //deixar 0-based
            saoAmigos[u] |= (1 << v);   //ligando o bit de amizade
        }

        int ans = 0;
        for(int i = 0; i < (1 << p); i++){
            int mask = (1 << p) - 1;
            for(int j = 0; j < p; j++){
                if((i >> j) & 1) mask &= saoAmigos[j];
            }
            ans = max(ans, __builtin_popcount(i) + __builtin_popcount(mask));
        }
        cout << ans << '\n';
    }

    return 0;
}
