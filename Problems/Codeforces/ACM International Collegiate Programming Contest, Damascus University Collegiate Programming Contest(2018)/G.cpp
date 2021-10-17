#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int mdc, mmc;

bool check(int num){
	return (mmc % num == 0) && (num % mdc == 0);
}

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a%b)); }
int lcm(int a, int b) { return a/gcd(a,b)*b; }

void solve(){
	
	int n;
	cin >> n >> mdc >> mmc;
	
	vector<int> a(n+2);
	
	if(n == 1){
		cin >> a[0];
		cout << (mdc == mmc ? !(a[0] == mdc) : -1) << endl;
		return;
	}
	
	vector<int> mdc_indo(n+2);
	vector<int> mdc_volt(n+2);
	vector<int> mmc_indo(n+2);
	vector<int> mmc_volt(n+2);
	
	int ans = 0;
	mdc_indo[0] = mmc;
	mdc_volt[n+1] = mmc;
	mmc_indo[0] = 1;
	mmc_volt[n+1] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(!check(a[i])){
			ans++;
			mdc_indo[i] = mdc_indo[i-1];
			mmc_indo[i] = mmc_indo[i-1];
			continue;
		}
		
		mdc_indo[i] = gcd(mdc_indo[i-1], a[i]);
		mmc_indo[i] = lcm(mmc_indo[i-1], a[i]);
	}
	
	for(int i = n; i >= 1; i--){
		if(!check(a[i])){
			mdc_volt[i] = mdc_volt[i+1];
			mmc_volt[i] = mmc_volt[i+1];
			continue;
		}
		
		mdc_volt[i] = gcd(mdc_volt[i+1], a[i]);
		mmc_volt[i] = lcm(mmc_volt[i+1], a[i]);
	}
	
	
	if(mmc % mdc){
		cout << -1 << endl;
		return;
	}
	
	if(ans > 1){
		cout << ans << endl;
		return;
	}
	
	if(mdc_indo[n] == mdc && mmc_indo[n] == mmc){
		cout << ans << endl;
		return;
	}
	
	vector<int> div;
	for(int i = 1; 1ll*i*i <= mmc; i++){
		if(mmc % i == 0){
			div.push_back(i);
			if(i != mmc/i)
				div.push_back(mmc/i);
		}
	}
	
	int mmc_at, mdc_at;
	for(int i = 1; i <= n; i++){
		mmc_at = lcm(mmc_indo[i-1], mmc_volt[i+1]);
		mdc_at = gcd(mdc_indo[i-1], mdc_volt[i+1]);
		for(int j = 0; j < div.size(); j++){
			if(mdc == gcd(mdc_at, div[j]) && mmc == lcm(mmc_at, div[j])){
				cout << 1 << endl;
				return;
			}
		}
	}
	
	cout << 2 << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();
}
