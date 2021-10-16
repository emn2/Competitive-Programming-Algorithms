#include "bits/stdc++.h"
using namespace std;
const int maxs = 1e5;
 
int dp[maxs+5] = {}, coins[105];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    memset(dp, -1, sizeof(dp));
 
    int n, ans = 0, sum = 0, sumAtual = 0;
    cin >> n;
 
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        sum += coins[i];
    }
    
    dp[0] = -2;
 
    for(int j = 0; j < n; j++){
        for(int i = 0; i <= sumAtual; i++){
            if(dp[i] != -1){
                if(dp[i+coins[j]] == -1 && dp[i] != j) dp[i+coins[j]] = j;
            }
        }
        sumAtual += coins[j];
    }
 
    for(int i = 1; i <= sum; i++)
        if(dp[i] >= 0) ans++;
 
    cout << ans << '\n';
 
    for(int i = 1; i <= sum; i++)
        if(dp[i] != -1) cout << i << ' ';
 
    return 0;
}
