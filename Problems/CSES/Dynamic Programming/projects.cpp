#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
#define max(a, b) ((a > b) ? a : b)
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n; 
    cin >> n;
    map<int, int> comp;
    vector<int> a(n), b(n), w(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> w[i];
        b[i]++;
        comp[a[i]], comp[b[i]];
    }
 
    int coord = 0;
    for(auto &v: comp) v.second = coord++;
 
    vector<vector<pair<int, int> > > proj(coord);
    for(int i = 0; i < n; i++)
        proj[comp[b[i]]].push_back(mp(comp[a[i]], w[i]));
 
    vector<ll> dp(coord, 0);
    for(int i = 0; i < coord; i++){
        if(i > 0) dp[i] = dp[i-1];
        for(auto p: proj[i]){
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
 
    cout << dp[coord-1] << '\n';
 
    return 0;
}
