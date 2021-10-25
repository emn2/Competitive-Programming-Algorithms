#include "bits/stdc++.h"
using namespace std;
#define int long long
 
const int mod = 1e9 + 7, maxn = 1e2, maxx = 1e6;
 
int dp[maxx+1], note[maxn+1];
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    memset(dp, 0, sizeof(dp));
 
    int x, n;
    cin >> x >> n;

    x *= 4;
 
    for(int i = 0; i < n; i++)
        cin >> note[i];
    
    dp[0] = 1;
 
    for(int i = 1; i <= x; i++)
        for(int j = 0; j < n; j++)
            if((i - note[j]) >= 0)
                dp[i] = (dp[i] + dp[i-note[j]])%mod;
 
    cout << dp[x] << '\n';
 
    return 0;
}
