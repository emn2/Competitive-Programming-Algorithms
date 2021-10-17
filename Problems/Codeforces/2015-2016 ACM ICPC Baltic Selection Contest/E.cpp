#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
typedef tuple<int, int, int> iii;

const int maxn = 1e5+10;
vector<int> adj[maxn];

int bit[maxn], n;

void update(int idx, int v){
	while(idx <= n) {
		bit[idx] += v;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ans = 0;
	while(idx > 0) {
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	
	int x;
	vector<iii> a;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a.emplace_back(min(i, x), 1ll, -max(i, x));
		a.emplace_back(max(i, x), 0ll, -min(i, x));
	}
	
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < a.size(); i++){
		auto [p, op, s] = a[i];
		
		s *= -1;
		if(op == 0){
			update(p, -1);
		}
		else {
			ans += query(s-1);
			update(s, 1);
		}
	}
	
	cout << ans << endl;
}
