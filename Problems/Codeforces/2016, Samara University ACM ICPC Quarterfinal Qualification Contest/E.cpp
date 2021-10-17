#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve(){
	
	int n;
	cin >> n;
	
	vector<ii> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	
	vector<ii> ev;
	for(int i = 0; i < n; i++){
		ev.emplace_back(a[i].first, 0);
		ev.emplace_back(a[i].second, 1);
	}
	
	sort(ev.begin(), ev.end(),greater<ii>());
	
	int mx = 0, at = 0;
	for(int i = 0; i < 2*n; i++){
		if(!ev[i].second)
			break;
		else
			at++;
		mx = max(mx, at);
	}
	
	cout << mx << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	while(tc--)
		solve();
}
