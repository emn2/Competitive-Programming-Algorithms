#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int LIM = 1e6 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll phi[LIM];
    bool isPrime[LIM];

    for(int i = 0; i < LIM; i++)
        phi[i] = i, isPrime[i] = true;

    for(int i = 2; i < LIM; i++){
        if(isPrime[i]){
            phi[i]--;
            for(int j = i*2; j < LIM; j+=i){
                isPrime[j] = false;
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }

    ll ans = 0, n;
    cin >> n;

    for(int i = 1; i<= n; i++) ans += phi[i];
    cout << ans << '\n';

    return 0;
}
