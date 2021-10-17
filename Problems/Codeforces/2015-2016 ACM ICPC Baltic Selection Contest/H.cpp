#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int r, c;
	cin >> r >> c;
	
	int ans = min(r*(c+1ll), c*(r+1ll));
	cout << ans << endl;
}
