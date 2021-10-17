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

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vi val(n);
  for(int i = 0; i < n; ++i) {
    cin >> val[i];
  }

  sort(ALL(val));

  ll qtt = 0;

  for(int i = 1; i < n; ++i) {
    ll diff = val[i] - val[i - 1] - 1;
    if(diff > 0) qtt += diff;
  }

  cout << qtt << endl;

  return 0;
}
