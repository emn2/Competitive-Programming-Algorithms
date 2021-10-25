#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

bool isRamp(string &s){
    int ult = 0;
    for(auto &c: s){
        int atual = c - '0';
        if(atual < ult) return false;
        ult = atual;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    ll dp[85][11];
    memset(dp, 0, sizeof(dp));

    dp[0][9] = 1;
    for(int i = 1; i <= 80; i++)
        for(int j = 9; j >= 0; j--)
            dp[i][j] = dp[i-1][j] + dp[i][j+1];


    while(t--){
        string s;
        getline(cin, s);
        if(!isRamp(s)) cout << "-1\n";
        else{
            ll ans = 0;
            ll now = 0;
            for(int i = 0; i < s.size(); i++){
                while(now < (s[i]-'0')){
                    ans += dp[s.size()-i][now];
                    now++;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
