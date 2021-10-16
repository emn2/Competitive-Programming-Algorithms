#include "bits/stdc++.h"
using namespace std;
 
const int mod = 1e9 + 7, maxn = 1e3;
int dp[maxn+1][maxn+1];
char grid[maxn+1][maxn+1];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    memset(dp, 0, sizeof(dp));
 
    int n;
    cin >> n;
 
    for(int i = 0; i < n*n; i++)
        cin >> grid[i/n][i%n];
 
    if(grid[0][0] != '*') dp[0][0] = 1;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i-1) >= 0 && grid[i][j] != '*') dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            if((j-1) >= 0 && grid[i][j] != '*') dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
        }
    }
 
    cout << dp[n-1][n-1] << '\n';
 
    return 0;
}
