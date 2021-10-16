#include "bits/stdc++.h"
using namespace std;
#define int long long
 
const int mod = 1e9 + 7, maxn = 1e2, maxx = 1e6;
 
int dp[maxx+1], coins[maxn+1];
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    memset(dp, 0, sizeof(dp));
 
    int n, x;
    cin >> n >> x;
 
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    
    dp[0] = 1;
 
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= x; j++)
            if((j - coins[i]) >= 0)
                dp[j] = (dp[j] + dp[j-coins[i]])%mod;
 
    cout << dp[x] << '\n';
 
    return 0;
}
