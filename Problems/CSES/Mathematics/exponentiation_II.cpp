#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
 
ll fexp(ll base, ll exp, ll MOD){
    ll ans = 1;
    while(exp > 0){
        if(exp & 1){
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ans;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
 
        cout << fexp(a, fexp(b, c, mod -1), mod) << '\n';
    }
 
    return 0;
}
