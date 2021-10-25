#include "bits/stdc++.h"
using namespace std;
#define i128 __int128
const int MAXN = 1005;

int n;
vector<int> a;
i128 dp[MAXN][MAXN];

i128 solve(int pos, int k){
    if(pos == n) return 1;
    if(dp[pos][k] != -1) return dp[pos][k];
 
    i128 ans = 0;
    if(!pos){
        ans += solve(pos + 1, 1);
        for(int i = 2; i <= k && a[pos + i - 1] > a[pos + i - 2]; i++)
            ans += solve(pos + i, i);
    } 
    else{
        if(a[pos] > a[pos - k]) {
            ans += solve(pos + 1, 1);
            for(int i = 2; i <= k && a[pos + i - 1] > a[pos + i - 2] && a[pos + i - 1] > a[pos - k + i - 1]; i++)
                ans += solve(pos + i, i);
        }
    }
    return dp[pos][k] = ans;
}

void print(i128 n) {
    if(n < 0) {
        cout << "-";
        n = -n;
    }
 
    if(n > 9) print(n / 10);
    int d = n % 10;
    cout << d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    i128 ans = solve(0, n);
    print(ans);

    return 0;
}
