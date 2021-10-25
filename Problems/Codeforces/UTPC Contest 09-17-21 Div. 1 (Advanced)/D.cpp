#include "bits/stdc++.h"
using namespace std;

#define int long long

int n, m;
vector<string> grid;

int solve(int i, int j){
    int cnt_up = 0;
    int cnt_down = 0;
    int cnt_left = 0;
    int cnt_right = 0;

    for(int dx = 1; i - dx >= 0; dx++){
        if(grid[i - dx][j] == '*') cnt_up++;
    }

    for(int dx = 1; dx + i < n; dx++){
        if(grid[i + dx][j] == '*') cnt_down++;
    }

    for(int dy = 1; dy + j < m; dy++){
        if(grid[i][j + dy] == '*') cnt_right++;
    }

    for(int dy = 1; j - dy >= 0; dy++){
        if(grid[i][j - dy] == '*') cnt_left++;
    }

    return (cnt_down*cnt_right + cnt_down*cnt_left + cnt_up*cnt_right + cnt_up*cnt_left);
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    grid.resize(n);

    for(int i = 0; i < n; i++) cin >> grid[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '*'){
                ans += solve(i, j);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
