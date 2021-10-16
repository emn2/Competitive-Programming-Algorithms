#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int maxn = 1e6, mod = 1e9 + 7;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n;
    cin >> n;
    vector<int> dp(maxn+1, 0);
    dp[0] = 1;
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= min(6, i); j++)
            dp[i] = (dp[i]+dp[i-j])%mod;
   
    cout << dp[n] << '\n';
 
    return 0;
}
