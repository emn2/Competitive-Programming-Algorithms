#include "bits/stdc++.h"
using namespace std;
const int maxx = 1e6, maxn = 1e2;
 
int n, x;
int dp[maxx+5];
int coins[maxn+1];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    memset(dp, -1, sizeof(dp));
 
    cin >> n >> x;
 
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
 
    for(int i = 1; i <= x; i++)
        for(auto e: coins)
            if(dp[i] != -1 && (i+e <= x))
                (dp[i+e] == -1) ? (dp[i+e] = dp[i]+1) : (dp[i+e] = min(dp[i+e], dp[i]+1));
        
    cout << dp[x] << '\n';
 
    return 0;
}
