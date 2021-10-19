#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b){
    return a*b/__gcd(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    
    ll val = 1LL;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        val = lcm(val, a);
    }

    ll ans = 0, best = 0;
    for(ll i = 1; i <= l; i++){
        ll new_val = lcm(val, i);
        if(new_val <= l && new_val > best){
            best = new_val;
            ans = i;
        }
    }

    cout << ans << '\n';
}
