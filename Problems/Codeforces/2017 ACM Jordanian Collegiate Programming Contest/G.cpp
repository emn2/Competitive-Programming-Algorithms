#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int freq[32];

void add(int x){
	for(int i = 0; i < 32; i++)
		if(x & (1 << i))
			freq[i]++;
}

void sub(int x){
	for(int i = 0; i < 32; i++)
		if(x & (1 << i))
			freq[i]--;
}

int calc(){
	int x = 0;
	for(int i = 0; i < 32; i++)
		if(freq[i])
			x |= (1 << i);
	return x;
}

void solve(){
	
	int n, v;
	cin >> n >> v;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	memset(freq, 0, sizeof freq);
	
	int mx = 0;
	int l = 0;
	for(int r = 0; r < n; r++){
		add(a[r]);
		while(l <= r && calc() > v){
			sub(a[l]);
			l++;
		}
		
		mx = max(mx, r-l+1);
	}
	
	cout << mx << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("wifi.in", "r", stdin);
	
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
