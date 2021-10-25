#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define endl '\n'

const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    freopen("Input.txt", "r", stdin); 
    freopen("Output.txt", "w", stdout);

    string str;
    cin >> str;

    vll dp(str.size()+5, 0);

    dp[0] = 1;
    for(int i = 1 ; i < str.size() ; i++){
        if(str[i] == 'N' || str[i] == 'S'){
            dp[i] = (dp[i] + dp[i-1])%mod;
        }else{
            if(str[i-1] == 'N' || str[i-1] == 'S'){
                dp[i] = (dp[i] + 2*dp[i-1])%mod;
            }else{
                dp[i] = (dp[i] + dp[i-1])%mod;
            }
        }
    }

    cout << dp[str.size()-1] << endl;

    return 0;
}
