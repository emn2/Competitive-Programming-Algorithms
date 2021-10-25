#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0LL) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("gcd.in", "r", stdin);

    int q;
    cin >> q;

    ll gcd_atual = 1;
    for(int i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        if(i == 0){
            if(l == r) gcd_atual = l;
        }
        else{
            if(l == r) gcd_atual = gcd(gcd_atual, l);
            else gcd_atual = 1;
        }
        cout << gcd_atual << '\n';
    }

    return 0;
}
