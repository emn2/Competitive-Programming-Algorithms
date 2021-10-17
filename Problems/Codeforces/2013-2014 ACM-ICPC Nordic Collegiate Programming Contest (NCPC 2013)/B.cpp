#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<ld, int>;


void solve(){

  ld ratio;
  int n;
  cin >> ratio >> n;

  priority_queue<ii> pq;
  int x;
  ld mn = 10000000, mx = 0;
  for(int i = 0; i < n; i++){
    cin >> x;
    pq.emplace(x, 1);
    mn = min<ld>(mn, x);
    mx = max<ld>(mx, x);
  }

  int ans = 0, cuts;
  while((mn/mx) < ratio){
    ans++;
    tie(mx, cuts) = pq.top();
    pq.pop();
    ld tot = mx * cuts;
    cuts++;
    pq.emplace(tot/cuts, cuts);
    mn = min<ld>(tot/cuts, mn);
    mx = pq.top().first;
  }

  cout << ans << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	while(tc--)
		solve();
}
