#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
	
	int n;
	cin >> n;
	int mn = 1e6+10, soma = 0;
	
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		mn = min(a, mn);
		soma += a;
	}
	
	if(n & 1){
		cout << (!(soma & 1) ? "Shin" : "Yalalov") << endl;
		return;
	}
	
	if(mn & 1){
		cout << "Yalalov" << endl;
		return;
	}
	
	cout << (!(soma & 1) ? "Shin" : "Yalalov") << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
