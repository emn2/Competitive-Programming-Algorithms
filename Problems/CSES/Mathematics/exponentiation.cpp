#include "bits/stdc++.h"
using namespace std;
#define int long long
 
const int mod = 1e9 + 7;
 
int fexp(int base, int exp){
    int ans = 1;
    while(exp > 0){
        if(exp & 1){
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans;
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << fexp(a, b) << '\n';
    }
 
    return 0;
}
