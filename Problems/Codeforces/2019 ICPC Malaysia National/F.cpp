#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;

const ll MOD = 1e9 + 7;
ll n, e, k, expo = 1, expo1 = 1;
set<ii> proibidos;
ll dp[2005][1000] = {};

ll solve(ll pos, ll mask){
	if(pos == n && (mask%expo1)==0) return 1;
	if(pos == n) return 0;
	if(dp[pos][mask]!=-1) return dp[pos][mask];

	ll resp = 0;

	ll x = mask, y = expo/2;
	for(ll i=pos-e;i<=pos+e;i++){
		if(i < 0){
			x <<= 1, y/=2;
			continue;
		}
		if(i >= n){
			break;
		}
		if(x&(expo/2)){
			x <<= 1, y/=2;
			continue;
		}
		if(proibidos.count({pos, i})) {
			x <<= 1, y/=2;
			continue;
		}
		resp += solve(pos+1, ((mask^y)<<1)%(expo))%MOD;
		resp %= MOD;
		x <<= 1, y/=2;
	}
	return dp[pos][mask] = resp;
}

int main() {
	  memset(dp, -1, sizeof(dp));
    scanf("%lld %lld %lld", &n, &e, &k);
    for(ll i=0;i<k;i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      a--, b--;
      proibidos.insert({a, b});
    }
    for(ll i=0;i<=2*e;i++) {
      if(i<=e) expo1 *= 2;
      expo *= 2;
    }
    ll resp = solve(0, 0);
    printf("%lld\n", resp);
    return 0;
}
