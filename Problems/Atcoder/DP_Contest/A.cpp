#include "bits/stdc++.h"
using namespace std;
#define int long long

const int maxn = 1e5 + 5;

int n;
int dp[maxn];
vector<int> h;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    h.resize(n);

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++)
        cin >> h[i];


    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);

    for(int i = 2; i < n; i++)
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));

    cout << dp[n-1] << '\n';

    return 0;
}
