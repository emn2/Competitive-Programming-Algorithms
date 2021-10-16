#include "bits/stdc++.h"
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAXW = 1e2 + 5;
const int MAXN = 1e5 + 5;
 
int n, m;
vector<int> a;
 
int dp[MAXN][MAXW] = {};
 
int solve(int pos, int last){
    if(last > m || last <= 0) return 0;
 
    if(pos == n) return 1;
 
    if(dp[pos][last] != -1) return dp[pos][last]; 
 
    int ans = 0;
 
    if(a[pos] != 0 && abs(a[pos]-last) <= 1){
        ans = (ans + (solve(pos + 1, a[pos]) % MOD)) % MOD;
    }
    else if(a[pos] == 0){
        ans = (ans + (solve(pos + 1, last - 1) % MOD)) % MOD;
        ans = (ans + (solve(pos + 1, last) % MOD)) % MOD;
        ans = (ans + (solve(pos + 1, last + 1) % MOD)) % MOD;
    }
    
    return dp[pos][last] = ans;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
 
    a.resize(n);
 
    for(int i = 0; i < n; i++) cin >> a[i];
 
    memset(dp, -1, sizeof(dp));
 
    int resp = 0;
 
    for(int i = 1; i <= m; i++){
        if(a[0] != 0) {
            resp = (resp + solve(1, a[0]));
            break;
        }
        resp = (resp + solve(1, i)) % MOD;
    }
 
    cout << resp << '\n';
 
    return 0;
}
