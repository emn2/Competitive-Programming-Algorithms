#include "bits/stdc++.h"
using namespace std;
const int N = 101;
const int V = 1001;

const int INF = 1e9 + 5;
 
int n, w_max;
int dp[N][N*V];
vector<int> w, value;
 
int solve(int pos, int sum){
    if(sum <= 0) return 0;
    if(pos == n) return INF;

    if(~dp[pos][sum]) return dp[pos][sum];

    int &ans = dp[pos][sum] = INF;

    ans = min(ans, solve(pos + 1, sum));
    ans = min(ans, w[pos] + solve(pos + 1, sum - value[pos]));

    return ans;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w_max;
 
    memset(dp, -1, sizeof(dp));
    w.resize(n+1), value.resize(n+1);
    
    for(int i = 0; i < n; i++)
        cin >> w[i] >> value[i];

    int ans = 0;
    for(int i = N*V - 1; i >= 0; i--){
        if(solve(0, i) <= w_max){
            ans = i;
            break;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
