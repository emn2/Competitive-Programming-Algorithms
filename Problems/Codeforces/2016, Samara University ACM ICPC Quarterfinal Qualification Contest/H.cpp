#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5+10;
vector<int> adj[maxn];

void solve(){
	
	string s;
	cin >> s;
	
	int a = 0, f = 0, q = 0, n = s.size();
	for(int i = 0; i < n; i++){
		a += (s[i] == '(');
		f += (s[i] == ')');
		q += (s[i] == '?');
	}
	
	if((n & 1) || abs(a - f) > q){
		cout << "Impossible" << endl;
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(s[i] == '?'){
			if(a == f + q)
				s[i] = ')';
			else{
				s[i] = '(';
				a++;
				q--;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += s[i] == '(';
		ans -= s[i] == ')';
		if(ans < 0){
			cout << "Impossible" << endl;
			return;
		}
	}
	
	if(ans != 0){
		cout << "Impossible" << endl;
		return;
	}
	
	cout << s << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	while(tc--)
		solve();
}
