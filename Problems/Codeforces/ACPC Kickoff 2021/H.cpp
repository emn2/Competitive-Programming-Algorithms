#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n;
vector<ll> a;

ll solve(int i){
    ll min_ = 1e11;
    for(int j = i, k = 0; j <= 2*n; j+=i) {
        min_ = min(min_, a[j]-a[k]);
        k = j;
    }
    return min_;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("bad-memes.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.assign(2*n + 5, 0);
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        for(int i = 1; i <= 2*n; i++) a[i] += a[i-1];

        ll ans = -1e11;
        for(int i = 1; i < n; i++){
            ans = max(ans, solve(i));
        }
        ans = max(ans, a[n]);
        cout << ans << '\n';
    }
    return 0;
}
