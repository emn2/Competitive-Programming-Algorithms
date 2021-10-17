#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int solve(ll n, int cnt){
    if(n / 10 == 0) return cnt;

    ll mult = 1, aux = n;
    while(aux > 0){
        mult *= (aux % 10);
        aux /= 10;
    }

    return solve(mult, cnt + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << solve(n, 0) << '\n';
    }

    return 0;
}
