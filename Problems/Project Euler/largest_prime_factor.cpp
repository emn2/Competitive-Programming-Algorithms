#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll fatorar(ll n){
    ll aux = n, maior = 0;
    for(ll i = 2; i*i <= aux; i++){
        while(n % i == 0){
            maior = max(maior, i);
            n /= i;
        }
    }
    return maior;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << fatorar(n) << '\n';
}
