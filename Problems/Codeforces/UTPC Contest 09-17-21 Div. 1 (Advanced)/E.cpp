#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    if((ll)pow(2, k) <= n) cout << 0 << '\n';
    else cout << (ll)pow(2, k-1) << '\n';

    return 0;
}
