#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll bom, ruim, colher;
        cin >> bom >> ruim >> colher;
        
        ll total_spoons = (bom + ruim + colher - 1)/colher;

        ll resto_bom = (bom % colher);
        ll resto_ruim = (ruim % colher);

        ll resp_max = bom/colher;
        if((resto_bom + resto_ruim  > colher) || (resto_bom > 0 && resto_ruim == 0)) resp_max++;

        cout << resp_max << ' ' << max(0LL, total_spoons - ruim) << '\n';
    }

    return 0;
}
