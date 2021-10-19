#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
const int MAXT = 55;
const int MAXN = 1e5 + 5;

int minimo, maximo, t;

int dp[MAXT][MAXN];

int solve(int pos, int last){
    if(last > maximo || last < minimo) return 0;

    if(pos == t) return 1;

    if(dp[pos][last] != -1) return dp[pos][last];

    int ans = 0;

    ans = (ans + (solve(pos + 1, last - 1) % MOD)) % MOD;
    ans = (ans + (solve(pos + 1, last + 1) % MOD)) % MOD;

    return dp[pos][last] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> minimo >> maximo;

    memset(dp, -1, sizeof(dp));

    int resp = 0;
    for(int i = minimo; i <= maximo; i++)
        resp = (resp + solve(1, i)) % MOD;

    cout << resp << '\n';
}
