#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;

// sn = a1+(q^n - 1) / q - 1

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
    cin.tie();
    int t;
    cin >> t;
    while(t--){
        int n, x, sum = 0;
        cin >> n >> x;
        sum = (x*(fexp(2,n) - 1));
        cout << sum % mod << '\n';
    }

    return 0;
}
