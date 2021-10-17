#include "bits/stdc++.h"
using namespace std;

#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c) 

const int MAXN = 1005;

vector<string> grid;

int n, m;
int dp[MAXN][MAXN];
bool vis[MAXN][MAXN] = {};

int solve(int i, int j){
    if(vis[i][j]) return dp[i][j];

    vis[i][j] = true;

    int ans = 1;
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            if(dx != 0 || dy != 0){
                int new_i = i + dx, new_j = j + dy;
                if(in_range(new_i, new_j, n, m) && (grid[i][j] + 1 == grid[new_i][new_j])){
                    ans = max(ans, 1 + solve(new_i, new_j));
                }
            }
        }
    }

    return dp[i][j] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    grid.resize(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]) solve(i, j);
        }
    }

    int resp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            resp = max(resp, dp[i][j]);
        }
    }

    cout << resp << '\n';

    return 0;
}
