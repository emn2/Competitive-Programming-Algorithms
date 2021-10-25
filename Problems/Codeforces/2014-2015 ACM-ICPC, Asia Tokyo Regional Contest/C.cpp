#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(m == 0){
        cout << n+1 << '\n';
        return 0;
    }

    vector<ii> intervals(m);

    for(int i = 0; i < m; i++){
        cin >> intervals[i].first >> intervals[i].second; 
    }

    sort(intervals.begin(), intervals.end());

    vector<ii> merged;
    int l = intervals[0].first, r = intervals[0].second;

    for(int i = 1; i < m; i++){
        if(intervals[i].first <= r){
            r = max(r, intervals[i].second);
        }
        else{
            merged.push_back(make_pair(l, r));
            l = intervals[i].first;
            r = intervals[i].second;
        }
    }

    merged.push_back(make_pair(l, r));

    ll ans = 0;
    l = 0;
    for(auto e: merged){
        ans = ans + 2*e.second - l - e.first;
        l = e.first;
    }
    ans = ans + n + 1 - l;

    cout << ans << '\n';

    return 0;
}
