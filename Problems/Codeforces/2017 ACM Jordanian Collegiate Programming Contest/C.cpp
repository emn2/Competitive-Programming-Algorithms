#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> freq(13);
	
	for(int i = 0 ; i < 13; i++)
		cin >> freq[i];
	
	for(int i = 0; i < n; i++)
		freq[s[i]-'A'] = 0;
	
	int mn = 0;
	for(int i = 0; i < 13; i++){
		if(freq[mn] < freq[i])
			mn = i;
	}
	
	cout << (char)('A'+mn) << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("scoreboard.in", "r", stdin);
	
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
