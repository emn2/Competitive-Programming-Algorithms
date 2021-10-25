#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("equal.in", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b || b == c || a == c) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
