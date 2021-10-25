#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool check(int m){
	for(int i = 0, j = m-1; j < n; ++i,++j){
		set<char> c;
		for(char x = 'A'; x <= 'Z'; ++x) c.insert(x);
		for(int l = i; l <= j; ++l){
			if(s[l] == *c.begin()){
				c.erase(s[l]);
			}
			if(c.empty()) break;
		}
		if(c.empty()) return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
 
	#ifdef ONLINE_JUDGE
	freopen("collectingofficer.in", "r", stdin); 
	#endif
	
	int t;
	cin >> t;
	for(int _ = 0; _ < t; ++_){
		
		cin >> n >> s;
		
		int l = 26, r = n;
		while(l < r){
			int m = (l+r)/2;
			if(check(m)) r = m;
			else l = m+1;
		}
		cout << (check(l)? l : r) << '\n';
	}
	return 0;
}
