#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve(ll n){
    if(n == 0)return {};
    if(n == 1)return {n};
    if(n % 2 == 0){
      vector<ll> r = solve(n/2);
      for(ll& x : r)x = x * 2;
      return r;
    }
    else{
      ll poty = 1;
      while(poty * 3 <= n) poty *= 3;
      vector<ll> r = solve(n - poty);
      r.push_back(poty);
      return r;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    freopen("distribution.in","r",stdin);
    freopen("distribution.out","w",stdout);
  
    int t;
    cin>>t;
  
    while(t--){
      ll n;cin>>n;
      vector<ll> ans = solve(n);
      cout<<(int)ans.size()<<'\n';
      for(ll x : ans)cout<<x<<' ';
      cout<<'\n';
    }
    return 0;
}
