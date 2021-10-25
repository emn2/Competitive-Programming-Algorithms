#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, t, ans = 0;
    cin >> n >> t;
    map<ll, ll> mp;
    vector<ll> v(n);
    vector<ll> positivos, negativos;
    for(ll &a: v) cin >> a;

    for(auto x: v){
        if(x < 0) negativos.push_back(x);
        else positivos.push_back(x);
    }

    for(int i = 0; i < negativos.size(); i++){
        mp[negativos[i]] = negativos.size()-i;
    }
    for(int i = 0; i < positivos.size(); i++){
        mp[positivos[i]] = i+1;
    }

    //pra usar o upper_bound
    for(int i = 0; i < negativos.size(); i++) negativos[i] *= -1;
    sort(negativos.begin(), negativos.end());

    //ir so para o lado dos positivos
    auto x = upper_bound(positivos.begin(), positivos.end(), t);
    if(x != positivos.begin()){
        x--;
        ans = max(ans, mp[*x]);
    }

    //ir so para o lado dos negativos
    auto y = upper_bound(negativos.begin(), negativos.end(), t);
    if(y != negativos.begin()){
        y--;
        int val = *y;
        val *= -1;
        ans = max(ans, mp[val]);
    }
    
    for(int i = 0; i < negativos.size(); i++){
        int resto = t - 2*negativos[i], prov = mp[-1*negativos[i]];
        if(resto <= 0) continue;
        else{
            auto z = upper_bound(positivos.begin(), positivos.end(), resto);
            if(z != positivos.begin()){
                z--;
                prov += mp[*z];
                if(prov > ans) ans = prov;
            }
        }
    }

    for(int i = 0; i < positivos.size(); i++){
        int resto = t - 2*positivos[i], prov = mp[positivos[i]];
        if(resto <= 0) continue;
        else{
            auto w = upper_bound(negativos.begin(), negativos.end(), resto);
            if(w != negativos.begin()){
                w--;
                int val = *w;
                val *= -1;
                prov += mp[val];
                if(prov > ans) ans = prov;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
