#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main(){  
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, c;
    cin >> n >> c;

    int cadeiras_vagas = c - n*3;
    int total = n + cadeiras_vagas;

    ll ans = 1;
    for(int i = total; i > cadeiras_vagas; i--){
        ans *= i;
        if(ans >= MOD) ans %= MOD;
    }

    for(int i = 1; i <= n; i++){
        ans = (ans * 6) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
