#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

long double PI = acos(-1.0L);

void solve(){
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	cout << fixed << setprecision(10);
	
	long double dist = (a-c) * (a-c) + (b-d) * (b-d);
	dist = sqrt(dist);
	
	long double area = (dist/3) * (7 * dist / 8) * PI;
	cout << area << endl; 
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tc = 1;
	while(tc--)
		solve();
}
