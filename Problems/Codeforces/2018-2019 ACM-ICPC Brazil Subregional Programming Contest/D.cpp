#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    int ans = 0;
 
    while(t--){
        int n;
        cin >> n;
        if(n != 1) ans++;
    }
 
    cout << ans << '\n';
 
    return 0;
}
