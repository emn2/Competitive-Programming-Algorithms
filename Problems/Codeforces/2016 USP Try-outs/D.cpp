#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> price;

ll solve(ll x){
    ll aux = 0;
    for(int i = n-1; i >= 1; i--){
        aux += (ll)(lower_bound(price.begin(), price.begin()+i, x-price[i])-price.begin());
        if(aux >= k) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll l = 0, r = 0;
    cin >> n >> k;
    price.resize(n);
    for(ll &a: price) cin >> a;
    sort(price.begin(), price.end());
    
    l = price[0]+price[1];
    r = price[n-2]+price[n-1];

    while(l <= r){
        ll mid = (l+r)/2;
        if(solve(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}

