#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, maiorElemento = 0, index = 0;
    cin >> n;
    vector<ll> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] > maiorElemento){
            maiorElemento = v[i];
            index = i;
        }
    }

    for(int i = 0; i < n; i++){
        if(maiorElemento % v[i] != 0){
            cout << "-1\n";
            return 0;
        }
    }

    cout << index + 1 << '\n';

    return 0;
}
