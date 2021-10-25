#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, h;
vector<vector<int> > dp;
vector<vector<int> > grid;

int solve(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= h) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int diag1 = solve(i-1, j+1) + grid[i][j];
    int right = solve(i, j+1) + grid[i][j];
    int diag2 = solve(i+1, j+1) + grid[i][j];

    return dp[i][j] = max(diag1, max(right, diag2));
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;
    cin >> n >> h;

    dp.resize(n+2);
    grid.resize(n+1);

    for(int i = 0; i < n; i++){
        grid[i].resize(h);
        dp[i].assign(h, -1);
        for(int j = 0; j < h; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        solve(i, 0);
    }

    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i][0]);

    cout << ans << '\n';

    return 0;
}
