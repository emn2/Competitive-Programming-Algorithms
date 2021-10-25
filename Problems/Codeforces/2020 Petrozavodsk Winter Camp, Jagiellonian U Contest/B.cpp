#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAXD = 20;
const int MAXN = 1e6 + 7;

ll dp[(1 << MAXD)];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        memset(dp, 0LL, sizeof(dp));

        for(int i = 0; i < n; i++){
            dp[a[i]] += 1;
        }

        for(int mask = 0; mask < MAXD; mask++){
            for(int i = 0; i < MAXN; i++){
                if(i & (1 << mask)){
                    dp[i] += dp[i ^ (1 << mask)];
                }
            }
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += dp[a[i]];
        }

        cout << ans << '\n';
    }

    return 0;
}

