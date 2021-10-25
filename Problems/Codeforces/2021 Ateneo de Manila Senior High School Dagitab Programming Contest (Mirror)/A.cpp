#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    a[0] = v[0];
    for(ll i = 1; i < n; i++)
        a[i] = v[i] - v[i-1];
    for(auto e: a)
        cout << e << ' ';

    return 0;
}
