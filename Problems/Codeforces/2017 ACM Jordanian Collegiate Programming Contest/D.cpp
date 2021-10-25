#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 5010;
int freq[maxn];
int check[maxn];
int at;

void solve(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(mp[a[i]] == 0)
			mp[a[i]] = mp.size();
		a[i] = mp[a[i]];
	}
	
	int impar = 0;
	int ans = 0;

	for(int i = 0; i < n; i++){
		impar = 0;
		for(int j = i; j >= 0; j--){
			if(check[a[j]] != at){
				check[a[j]] = at;
				freq[a[j]] = 0;
			}
			
			freq[a[j]]++;
			if(freq[a[j]] & 1)
				impar++;
			else
				impar--;
			ans += impar == 1;
		}
		at++;
	}
	
	cout << ans << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("cases.in", "r", stdin);
	
	at = 1;
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
