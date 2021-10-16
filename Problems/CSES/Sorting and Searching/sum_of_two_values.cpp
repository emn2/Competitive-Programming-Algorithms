#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
 
ii sumOfTwo(map<int, int> &mp, vector<int> &v, int x){
    for(int i = 0; i < v.size(); i++){
        mp[v[i]]--;
        if(v[i] > x){
 
        }
        else {
            if(mp[x - v[i]] > 0){
                return {i+1, x - v[i]};
            }
        }
        mp[v[i]]++;
    }
    return {-1, -1};
}
 
int main(){
    int n, x, p2;
    cin >> n >> x;
    map<int, int> mp;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
        v.push_back(a);
    }
 
    ii ans = sumOfTwo(mp, v, x);
 
    if(ans.first == -1){
        cout << "IMPOSSIBLE\n";
    }
    else {
        for(int i = 0; i < v.size(); i++){
            //cout << i << " " << v[i] << '\n';
            if(v[i] == ans.second && i != ans.first - 1) {
                p2 = i+1;
                break;
            }
        }
        cout << ans.first << " " << p2 << '\n'; 
    }
    return 0;
}
