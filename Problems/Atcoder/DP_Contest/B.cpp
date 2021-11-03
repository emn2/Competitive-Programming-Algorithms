#include "bits/stdc++.h"
using namespace std;
#define int long long

const int maxn = 1e5 + 5;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int dp[maxn];
    int n, k, l;
    cin >> n >> k;

    vector<int> h (n);

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++)
        cin >> h[i];


    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);

    for(int i = 2; i < n; i++){
        int zero = 0;
        l = max(i-k, zero);
        for(int j = l; j < i; j++){
            if(dp[i] == -1) dp[i] = dp[j] + abs(h[i] - h[j]);
            else dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n-1] << '\n';

    return 0;
}
