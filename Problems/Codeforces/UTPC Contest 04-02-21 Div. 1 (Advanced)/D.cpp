#include "bits/stdc++.h"
using namespace std;

typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ld a, b, xa, xb;
    vector<int> alice(n), bob(n);

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        a /= 440.0; b /= 440.0;

        xa = log2(a)*12;
        xb = log2(b)*12;
        
        alice[i] = round(xa);
        bob[i] = round(xb); 
    }

    int ans = 1e9;

    for(int i = -1000; i <= 1000; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += bob[j] - alice[j] + i;
        }
        ans = min(ans, abs(sum));
    }

    cout << ans;

    return 0;
}
