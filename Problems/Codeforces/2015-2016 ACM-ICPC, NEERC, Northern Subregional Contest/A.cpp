#include "bits/stdc++.h"
using namespace std;

typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);

    cout << setprecision(6) << fixed;

    ld a, b;
    cin >> a >> b;

    ld resp = 0, ld_atual = 0;

    if(a > b) swap(a, b);

    ld_atual = a/2;

    if(b >= 3*a) ld_atual = max(ld_atual, a);
    else if(b >= a && b < 3*a) ld_atual = max(ld_atual, b/3);
    
    cout << ld_atual << '\n';

    return 0;
}
