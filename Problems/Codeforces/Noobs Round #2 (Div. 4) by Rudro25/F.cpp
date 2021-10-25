#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
//num of intervals with # of unique elements at most k
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n, k, ans = 0, l = 0, r = -1, unique = 0, sumTotal = 0;
        cin >> n >> k;
        
        vector<ll> v(n);
        map<int, int> cnt;
        for(int i = 0; i < n; i++) cin >> v[i];
        
        for(l = 0; (l < n) && (r < n); l++){
            while((sumTotal <= k) && (r<n)){
                if(sumTotal <= k) ans = max((r-l+1), ans);
                r++;
                cnt[v[r]]++;                       //incrementa a qntd na seq
                if(cnt[v[r]] == 1) {
                    sumTotal += v[r];
                }
            }
            cnt[v[l]]--;
            if(cnt[v[l]] == 0) sumTotal -= v[l];
        }
        
        cout << ans << '\n';
        cnt.clear();
    }
    
    return 0;
}
