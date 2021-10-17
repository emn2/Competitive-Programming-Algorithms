#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
const int inf = 1e18;

bool primo(int x){
	for(int i = 2; i < x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int x = 1;
	vector<int> fat;
	set<int> s1, s2;
	for(int i = 2; i <= 20; i++){
		x *= i;
		fat.push_back(x);
		s2.insert(x);
	}
	
	s1.insert(1);
	s2.insert(1);
	__int128 sl;
	while(s1.size() < s2.size()){
		for(int x : s2)
			s1.insert(x);
			
		for(int i = 0; i < fat.size(); i++) for(int x : s1){
			sl = ((__int128)x) * fat[i];
			if(sl <= inf)
				s2.insert((long long) sl);
		}
	}
	
	
	int n;
	cin >> n;
	int a;
	while(n--){
		cin >> a;
		
		cout << (s1.count(a) ? "YES" : "NO") << endl;
	}
}
