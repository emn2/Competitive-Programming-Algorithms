#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5+10;
vector<int> adj[maxn];

void solve(){
	
	int n;
	cin >> n;
	
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[0] = 0;
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += max(a[i] - a[i-1], 0ll);
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
