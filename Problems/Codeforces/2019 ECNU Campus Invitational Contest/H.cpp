#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll sum (ll n) {
    if(n%2 == 0) {
        return (n/2)*(n-1);
    }
    return (n)*((n-1)/2);
}

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

void simplify(ll a, ll b) {
    ll div = 2;
    ll sa = a/2, sb = b/2;
    while(min(sa, sb) >= div) {
        cout << min(sa, sb) << " " << div << endl;
        while(a % div == 0 && b % div == 0) {
            a /= div;
            b /= div;
        }
        div++;
    }
    cout << a << "/" << b << endl;
}

int main() {
    ll h, m;
    cin >> h >> m;
    ll length = h * m;
    ll resp = 0;
    if(h <= m) {
        resp = length - sum(h);
    } 
    else {
        resp = sum(m) + m;
    }
    ll gg = gcd(resp, length);
    cout << resp / gg << "/" << length / gg << endl;
}
