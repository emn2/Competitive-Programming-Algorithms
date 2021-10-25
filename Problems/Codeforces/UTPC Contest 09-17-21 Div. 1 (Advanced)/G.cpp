#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 6;

int n, k;

ll dp[MAXN];
vector<ll> a;

//op 1: descer e pegar tudo
//op 2: descer e pegar metade
//op 3: nao descer

ll solve(int i){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];

    ll ans = 0;

    ans = max(ans, solve(i + k + 1) + a[i]);
    ans = max(ans, solve(i + k/2 + 1) + a[i]/2);
    ans = max(ans, solve(i + 1));


    return dp[i] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    a.resize(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(0) << '\n';

    return 0;
}
