#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;
const int hmax = 1e3 + 5;

int h, w;
int dp[hmax][hmax];
char grid[hmax][hmax];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> h >> w;

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#') dp[i][j] = 0;
            else 
                if(i != 0 || j != 0) 
                    dp[i][j] = ((i > 0)?dp[i-1][j]:0) + ((j>0)?dp[i][j-1]:0);
            if(dp[i][j] >= mod)
                dp[i][j] -= mod;
        }
    }

    cout << dp[h-1][w-1] << '\n';
    
    return 0;
}
