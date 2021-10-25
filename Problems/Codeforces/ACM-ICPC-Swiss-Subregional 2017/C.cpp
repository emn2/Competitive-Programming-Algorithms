#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        if(n % 3 == 0) cout << n/3 << ' ' << n/3 << ' ' << n/3 << '\n';
        else if(n % 4 == 0) cout << n/2 << ' ' << n/4 << ' ' << n/4 << '\n';
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}
