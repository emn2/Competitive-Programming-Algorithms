#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("overcode.in", "r", stdin);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        if(n < 6) {
            cout << 0 << '\n';
            continue;
        }

        sort(a.begin(), a.end());

        int ans = 0;
        for(int i = 0; i+5 < n; i++){
            if(a[i+5]-a[i] <= 1000){
                ans++;
                i += 5;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
