#include "bits/stdc++.h"
using namespace std;
typedef pair<int, pair<int, int> > iii;

const int maxn = 1e5 + 5;

int n;
int dp[maxn][3];
vector<iii> v;

int solve(int pos, int ult){
    if(pos > n) return 0;
    if(dp[pos][ult] != -1) return dp[pos][ult];

    int opt0 = 0, opt1 = 0, opt2 = 0;
    if(ult != 0)
        opt0 = solve(pos+1, 0) + v[pos].first;
    if(ult != 1)
        opt1 = solve(pos+1, 1) + v[pos].second.first;
    if(ult != 2)
        opt2 = solve(pos+1, 2) + v[pos].second.second;

    return dp[pos][ult] = max(opt0, max(opt1, opt2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; 

    v.resize(n+1);

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i++)
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;

    cout << solve(0, 100001) << '\n';

    return 0;
}
