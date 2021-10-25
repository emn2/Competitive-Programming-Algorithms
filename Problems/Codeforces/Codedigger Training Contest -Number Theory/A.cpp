#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int t;
    cin >> t;

    while(t--){
        int n, x, sum = 0;
        set<int> s;
        cin >> n >> x;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            s.insert(a);
        }
        sum = (x*(x+1))/2;

        for(auto e: s){
            if(e <= x)
                sum -= 2*e;
            else break;
        }
        cout << sum << '\n';
    }

    return 0;
}
