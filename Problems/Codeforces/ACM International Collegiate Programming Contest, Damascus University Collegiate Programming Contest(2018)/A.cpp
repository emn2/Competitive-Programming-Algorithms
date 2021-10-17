#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){    
        ll a, b;
        cin >> a >> b;
        if(a*a > 2*b*b) cout << "1\n";
        else cout << "2\n";
    }

    return 0;
}
