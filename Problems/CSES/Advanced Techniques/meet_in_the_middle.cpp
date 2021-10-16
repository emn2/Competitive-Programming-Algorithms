#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
int target;
 
void solve(int pos, vector<int> &num, map<ll, ll> &mp, ll sum){
    if(pos == num.size() || sum > target) return;
 
    mp[sum + num[pos]]++;
 
    solve(pos + 1, num, mp, sum);
    solve(pos + 1, num, mp, sum + num[pos]);
    
    return;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n >> target;
 
    map<ll, ll> mp1;
    map<ll, ll> mp2;
 
    vector<int> a, b; 
 
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i % 2) a.push_back(x);
        else b.push_back(x);
    }
 
    solve(0, a, mp1, 0);
    solve(0, b, mp2, 0);
 
    ll ans = 0;
 
    for(auto e: mp1){
        if(e.first == target) ans += (ll)e.second;
        ans += (ll)e.second*mp2[(target - e.first)];
    }
 
    ans += mp2[target];
 
    cout << ans << '\n';
 
    return 0;
}
