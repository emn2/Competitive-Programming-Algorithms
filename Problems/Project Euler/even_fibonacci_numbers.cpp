#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll sum = 0;
    ll a1 = 1, a2 = 1;
    while(a2 <= 4000000){
        ll a3 = a1 + a2;
        if(a3 % 2 == 0) sum += a3;

        a1 = a2;
        a2 = a3;
    }
    cout << sum << '\n';
}
