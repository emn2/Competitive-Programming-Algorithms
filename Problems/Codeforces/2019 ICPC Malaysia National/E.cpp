#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e3 + 5;

int t, n, ans = 0;
int dp[maxn][maxn];
vector<int> v, res;

int solve(int pos, int total){
    if(pos >= n) return 0;
    if(dp[pos][total] != - 1) return dp[pos][total];
    int usar = 0, nao_usar = solve(pos+1, total);
    if(total + v[pos] <= t)
        usar = solve(pos+1, total + v[pos]) + v[pos];
    return dp[pos][total] = max(usar, nao_usar);
}

void recover_solution(int pos, int total, int remaining){
    if(pos >= n || dp[pos][total] == -1) return;
    if(total + v[pos] <= t && solve(pos+1, total + v[pos]) == remaining - v[pos]){
        res.push_back(v[pos]);
        return recover_solution(pos+1, total + v[pos], remaining - v[pos]);
    }
    return recover_solution(pos+1, total, remaining);
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while((cin >> t >> n) && t != 0){
        v.resize(n);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)
            cin >> v[i];
        
        ans = solve(0, 0);
        recover_solution(0, 0, ans);
        
        for(auto e: res)
            cout << e << ' ';
        cout << ans << '\n';
        v.clear();
        res.clear();
    }

    return 0;
}
