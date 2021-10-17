#include "bits/stdc++.h"
using namespace std;
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 1e6 + 5;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int A, T; 
    cin >> A >> T;

    int cnt = 0;
    map<int, int> comp;
    vector<int> a, b, w;

    for(int i = 0; i < A; i++){
        int happy, duration, qnt_init;
        cin >> happy >> duration >> qnt_init;
        for(int j = 0; j < qnt_init; j++){
            int beggining;
            cin >> beggining;
            if(beggining <= T){
                a.push_back(beggining);
                b.push_back(beggining + duration);
                w.push_back(happy);
                comp[a[cnt]], comp[b[cnt]];
                cnt++;
            }
        }
    }

    int coord = 0;
    for(auto &v: comp) v.second = coord++;

    vector<vector<ii> > activities(coord);

    for(int i = 0; i < a.size(); i++)
        activities[comp[b[i]]].push_back(mp(comp[a[i]], w[i]));
 
    vector<ll> dp(coord, 0);
    for(int i = 0; i < coord; i++){
        if(i > 0) dp[i] = dp[i-1];
        for(auto p: activities[i]){
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
 
    cout << dp[coord-1] << '\n';
 
    return 0;
}
