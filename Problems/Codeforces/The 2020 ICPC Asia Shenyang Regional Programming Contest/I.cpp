#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll H, M, A;
    cin >> H >> M >> A;

    ll gcd_ = gcd(H - 1, H*M);

    if(A == H*M/2) cout << H*M << '\n';
    else cout << gcd_*(2*(A/gcd_) + 1);

    return 0;
}
