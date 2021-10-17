#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef long double ld;

const ll ms = 8000;
const ll MOD = 7901;
ll fat[ms];

int main () {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    fat[0] = 1;
    for (ll i = 1; i < ms; i++) {
        fat[i] = i*fat[i-1];
        fat[i] %= MOD;
    }
    while (t--) {
        int n; cin >> n;
        map<ll,ll> cnt;
        for (int i = 0; i < n; i++) {
            ll num; cin >> num;
            cnt[num]++;
        }
        ll ans = 1;
        for (auto e : cnt) {
            ans *= fat[e.S];
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
