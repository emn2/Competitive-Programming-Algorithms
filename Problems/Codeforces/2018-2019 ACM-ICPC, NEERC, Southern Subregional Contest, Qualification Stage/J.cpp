#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0LL) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, x, y;

    cin >> a >> b >> x >> y;

    ll gcd_x_y = gcd(x, y);

    x /= gcd_x_y;
    y /= gcd_x_y;

    cout << min(a/x, b/y);

    return 0;
}
