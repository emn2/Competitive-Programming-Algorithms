#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
 
ll inverse(ll i){
    if(i == 1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n;
    cin >> n;
 
    if(n % 2 == 1) cout << 0 << '\n';
    else{
        n /= 2;
        ll fact[2*n + 1];
        fact[0] = 1;
        for(int i = 1; i <= 2*n; i++){
            fact[i] = (fact[i-1]*i) % MOD;
        }
        ll ans = (fact[2*n]*inverse(fact[n])) % MOD;
        ans *= (inverse(fact[n])*inverse(n+1)) % MOD;
        ans %= MOD;
        cout << ans << '\n';
    }
 
    return 0;
}
