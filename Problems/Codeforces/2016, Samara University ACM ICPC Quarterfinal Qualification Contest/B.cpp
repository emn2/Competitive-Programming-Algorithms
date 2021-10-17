#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(auto &[a,b] : v)cin>>a>>b;
    sort(begin(v),end(v),[](auto &p1, auto &p2){
        if(p1.first - p1.second != p2.first - p2.second){
            return p1.first - p1.second > p2.first - p2.second;
        }else{
            return p1.second < p2.second;
        }
    });
    long long ans = 0;
    long long cur = 0;
    for(auto [a,b] : v){
        long long dif = max(0ll, a - cur);
        ans += dif;
        cur += dif - b;
    }
    cout<<ans<<'\n';
    return 0;
}
