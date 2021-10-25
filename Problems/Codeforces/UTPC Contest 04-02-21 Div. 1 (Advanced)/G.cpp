#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll sum(int l, int r){
    return (r-l+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> s;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        auto itl = s.upper_bound(a);
        auto itr = s.upper_bound(a);

        if(itl != s.begin()) itl--;

        int l = *itl;
        int r = *itr;
    
        bool lInclusive = false, rInclusive = false;

        if(l < 1 || l > n || l >= a) {
            l = 1;
            lInclusive = true;
        }
        if(r < 1 || r > n || r <= a) {
            r = n;
            rInclusive = true;
        }

        ans += sum((lInclusive)?l:l+1, (rInclusive)?r:r-1);

        s.insert(a);        
    }

    cout << ans << '\n';

    return 0;
}
