#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("tabs.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n == 1) cout << 0 << '\n';
        else if(k == 1 || k == n) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    return 0;
}
