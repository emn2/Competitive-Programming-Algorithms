#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5+10;
vector<int> adj[maxn];

void solve(){
	
	int n, m;
	cin >> n >> m;
	
	vector<int> freq(n);
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		freq[a]++;
		freq[b]++;
	}
	
	int mn = n+1;
	for(int i = 0; i < n; i++){
		mn = min(mn, freq[i]);
	}
	
	vector<int> ans(n, 1);
	for(int i = 0; i < n; i++){
		if(freq[i] == mn){
			ans[i] = 0;
			for(int x : adj[i])
				ans[x] = 0;
			break;
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1==n]; 
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tc = 1;
	while(tc--)
		solve();
}
