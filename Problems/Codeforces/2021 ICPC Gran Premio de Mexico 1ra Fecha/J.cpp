#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int dist[MAXN], parent[MAXN];
vector<vi> adj;

void dfs(int u) {
  if(!adj[u].size()) {
    dist[u] = 1;
    return;
  }

  for(auto v: adj[u]) {
    dfs(v);
    dist[u] = min(dist[u], 1 + dist[v]);
  }
}

void checkParent(int u) {
  dist[u] = min(dist[u], 1 + dist[parent[u]]);

  for(auto v: adj[u]) {
    checkParent(v);
  }
}

ll invmod(ll x) {
  ll e = MOD - 2;
  ll sum = 1;
  ll cur = x;
  while (e > 0) {
    if (e % 2) {
      sum *= cur;
      sum %= MOD;
    }
    cur = cur * cur % MOD;
    e /= 2;
  }
  return sum;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  adj.resize(n);

  for(int i = 0; i < n; ++i) {
    dist[i] = INF;
  }
  memset(parent, 0, sizeof parent);

  int input;
  for(int i = 1; i < n; ++i) {
    cin >> input;
    --input;
    parent[i] = input;
    adj[input].PB(i);
  }

  for(int i = 0; i < n; ++i) {
    if(dist[i] == INF) {
      dfs(i);
      checkParent(i);
    }
  }

  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    ans += dist[i];
  }

  ll gcd = __gcd(ans, (ll)n);
  ans /= gcd;
  n /= gcd;

  ans *= invmod(n);
  ans %= MOD;

  cout << ans << endl;

  return 0;
}
