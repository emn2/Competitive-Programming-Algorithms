#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n, ans = 0;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> mp;
        for(auto &a: v) cin >> a;
        for(auto e: v) mp[e]++;
        for(int i = 0; i < n; i++){
            mp[v[i]]--;
            for(int j = i-1; j >= 0; j--){
                ll procurado = 2*v[i] - v[j];
                if(mp.count(procurado)) 
                    ans += mp[procurado];
            }
        }
        mp.clear();
        cout << ans << '\n';
    }

    return 0;
}

