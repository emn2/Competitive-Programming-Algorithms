#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    vector<int> pref(n, 0);
    double arc = sum / 3;
    set<int> s;

    s.insert(0);
    for(int i = 1; i < n; i++){
        pref[i] += pref[i - 1] + v[i];
        s.insert(pref[i]);
    }

    int ans = 0;
    for(int i = 1; i < n-1; i++){
        if(s.count(pref[i] - arc) && s.count(pref[i] + arc)) ans++;
    }
    
    cout << ans << '\n';

}
