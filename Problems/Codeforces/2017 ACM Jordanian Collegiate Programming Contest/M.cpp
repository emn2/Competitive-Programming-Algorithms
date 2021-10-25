#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define endl '\n'

int main(){    
    freopen("chess.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    ll n, k;
    while(t--){
        cin >> n >> k;
        ll ans = n*n;

        ll x = n/(k+1);
        ll y = n%(k+1);

        ans -= x*x*(k+1);
        ans -= (2*x+1)*y;

        cout << ans << endl;
    }
}
