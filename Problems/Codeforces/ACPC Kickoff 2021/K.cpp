#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("help.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);

        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int idx1 = 0, idx2 = 0, m1 = 0, m2 = 0;

        for(int i = 0; i < n; i++){
            if(a[i] > m1 || (a[i] == m1 && idx1 == 0)){
                idx2 = idx1;
                idx1 = i;
                m2 = m1;
                m1 = a[i];
            }
            else if(a[i] > m2){
                idx2 = i;
                m2 = a[i];
            }
        }

        ll ans = sum - a[idx1] - a[idx2];

        for(int i = 1; i < n; i++) a[i] += a[i-1];

        if(n == 1 || n == 2) cout << 0 << '\n';
        else if(n == 3) cout << ans << '\n';
        else{
            for(int i = 0; i < n-1; i++){
                if(i == 0)
                    ans = min(ans, a[n-1] - a[1]);
                else if(i == n-2){
                    ans = min(ans, a[i-1]);
                }
                else{
                    ans = min(ans, max(a[i-1], a[n-1] - a[i+1]));
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
