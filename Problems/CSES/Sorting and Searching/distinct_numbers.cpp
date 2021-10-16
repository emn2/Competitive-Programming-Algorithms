#include "bits/stdc++.h"
using namespace std;
#define int long long
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, cnt = 0;
    map<int, int> mp;
 
    cin >> n;
 
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(mp[a] == 0){
            cnt++;
            mp[a]++;
        }
    }
 
    cout << cnt << '\n';
 
    return 0;
}
