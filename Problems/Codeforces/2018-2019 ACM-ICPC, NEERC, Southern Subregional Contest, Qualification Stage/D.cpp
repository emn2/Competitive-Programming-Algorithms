#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
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

const int MAXN = 1e7;

vector<vector<pii>> pairs(MAXN);
vector<int> qtt(MAXN);
vector<int> idx(MAXN);

void findDiv(int n) {
  for(int i = 1; i*i <= n; ++i) {
    if(n%i == 0) {
      pairs[n].emplace_back(i, n/i);
      if(n/i != i) pairs[n].emplace_back(n/i, i);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vi val(n);
  
  for(int i = 0; i < n; ++i) {
    cin >> val[i];
    qtt[val[i]]++;
    if(pairs[val[i]].size() == 0) {
      findDiv(val[i]);
    }
  }

  bool possib = true;

  for(auto i: val) {
    if(qtt[i] > pairs[i].size()) possib = false;
  }

  if(possib) {
    cout << "YES" << endl;
    for(auto i: val) {
      auto cur = pairs[i][idx[i]];
      idx[i]++;
      cout << cur.F << " " << cur.S << endl;
    }
  } 
  else {
    cout << "NO" << endl;
  }

  return 0;
}
