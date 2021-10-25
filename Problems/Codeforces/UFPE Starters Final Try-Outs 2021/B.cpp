#include "bits/stdc++.h"
using namespace std;
#define pb push_back


int main(){
    int n;
    cin >> n;

    vector<vector<int> > adj(20);

    for(int i = 0; i < n; i++){
        int q; cin >> q;
        for(int j = 0; j < q; j++){
            int a; cin >> a;
            a--;
            adj[i].pb(a);
        }
    }
    int ans = 0, sz = (1 << n);
    bool ok = true;

    for(int mask = 1; mask < sz; mask++){
        ok = true;
        int total = 0;

        for(int i = 0; i < n; i++){
            if((1 << i) & mask){
                total++;
                for(auto j: adj[i]){
                    if((1 << j) & mask){    //houve contradicao
                        ok = false;
                        break;
                    }
                }
            }
        }

        if(ok){
            int qntd = 0;
            for(int i = 0; i < n; i++){
                bool foi = false;
                if(!((1 << i) & mask)){
                    for(auto j: adj[i]){
                        if((1 << j) & mask){
                            foi = true;
                            break;
                        }
                    }
                    if(!foi) break;
                    else qntd++;
                }
            }
            if(qntd == n-total) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
