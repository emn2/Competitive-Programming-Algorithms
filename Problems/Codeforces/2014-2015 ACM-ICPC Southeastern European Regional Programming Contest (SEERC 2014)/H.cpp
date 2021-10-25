#include "bits/stdc++.h"
#define inf 1000001 //DEPENDS ON THE PROBLEM
#define ll long long
#define endl '\n'

using namespace std;

bool has_root(ll a) {
  ll up = ceil(sqrt(a));
  ll bot = sqrt(a);
  return up == bot;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("h.in", "r", stdin);
  ll m, n;
  cin >> m >> n;
  ll resp = 0;
  for(ll y = 0; y <= m; y++) {
    for(ll x = 0; x <= y; x++) {
      ll sum = (x*x) + (y*y);
      if(has_root(sum)) {
        if(sqrt(sum) <= m) {
          resp++;
        }
        
      } 
    }
  }

  cout << resp + (m+1)*(n-2) << endl;
}
