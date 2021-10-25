#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << setprecision(12) << fixed;

    ll n;
    cin >> n;
    ld a, b, xa, xb;
    ll ia, ib, resp = 0, cont = 0;

    while(n--){
        cin >> a >> b;
        a /=440;   b /=440;
        xa = log2(a)*12; 
        xb = log2(b)*12;
        ld dif = abs(xb - xa);
        ld dif2 = dif - ll(dif);
        ll resp = ll(dif);
        if(dif2 > 0.5){
            resp++;
        }
        if(a > b){
            resp = -resp;
        }
        cont += resp;
    }
    cont = abs(cont);
    cout << cont << '\n';
    return 0;
}
