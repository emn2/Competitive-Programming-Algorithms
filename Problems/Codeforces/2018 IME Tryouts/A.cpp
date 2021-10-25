#include "bits/stdc++.h"
using namespace std;

#define int long long
 
const int mod = 1e9 + 7;

int dp[2][8] = {};

void copy(){
    for(int i = 0; i < 8; i++){
        dp[0][i] = dp[1][i];
        dp[1][i] = 0;
    }
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    dp[0][7] = 1;
 
    while(n-- > 0){
        int i = 1;
        dp[i][0] = (dp[i][0] + dp[i-1][7]) % mod;
        dp[i][1] = (dp[i][1] + dp[i-1][6]) % mod;
        dp[i][3] = (dp[i][3] + dp[i-1][7] + dp[i-1][4]) % mod;
        dp[i][4] = (dp[i][4] + dp[i-1][3]) % mod;
        dp[i][6] = (dp[i][6] + dp[i-1][7] + dp[i-1][1]) % mod;
        dp[i][7] = (dp[i][7] + dp[i-1][0] + dp[i-1][3] + dp[i-1][6]) % mod;
        
        copy();
    }

    cout << dp[0][7] << '\n';
 
    return 0;
}
