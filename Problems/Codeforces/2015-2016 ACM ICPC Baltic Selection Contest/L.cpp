#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int h = 0, sd = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == ':'){
			if(i){
				h += s[i-1] == '(';
				sd += s[i-1] == ')';
			}
			if(i+1 < n){
				h += s[i+1] == ')';
				sd += s[i+1] == '(';
			}
		}		
	}
	
	cout << (sd == h ? "BORED" : (h > sd ? "HAPPY" : "SAD")) << endl; 
}
