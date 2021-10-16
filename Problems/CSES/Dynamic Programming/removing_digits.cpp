#include "bits/stdc++.h"
using namespace std;
 
int maiorDig(int x){
    int d = 0;
    while(x > 0){
        d = max(d, x%10);
        x /= 10;
    }
    return d;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, ans = 0;
    cin >> n;
 
    while(n > 0){
        int higher = maiorDig(n);
        ans++;
        n -= higher;
    }
 
    cout << ans << '\n';
 
    return 0;
}
