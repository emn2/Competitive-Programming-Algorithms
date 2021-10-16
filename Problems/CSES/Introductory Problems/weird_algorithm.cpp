#include "bits/stdc++.h"
using namespace std;
#define int long long
 
void solve(int n){
    cout << n << " ";
    if(n == 1) return;
    if(n % 2 == 0) solve(n / 2);
    else solve(3*n + 1);
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    solve(n);
 
    cout << '\n';
 
    return 0;
}
