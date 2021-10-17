#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Pessoa{
	int l, r, dir, at, nxt;
};

void solve(){
	
	Pessoa s, f;
	cin >> s.l >> s.r >> s.at >> s.dir;
	if(s.dir == 0)
		s.dir = -1;
	cin >> f.l >> f.r >> f.at >> f.dir;
	if(f.dir == 0)
		f.dir = -1;
	
	int k;
	cin >> k;
	int ans = s.at == f.at;
	while(k--){
		if(s.at == s.l)
			s.dir = 1;
		if(f.at == f.l)
			f.dir = 1;
		if(s.at == s.r)
			s.dir = -1;
		if(f.at == f.r)
			f.dir = -1;
		
		s.nxt = s.at + s.dir;
		f.nxt = f.at + f.dir;
		
		ans += (s.nxt == f.nxt);
		s.at = s.nxt;
		f.at = f.nxt;
	}
	
	cout << ans << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
