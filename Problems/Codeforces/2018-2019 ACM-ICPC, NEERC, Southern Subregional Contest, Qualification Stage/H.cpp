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

  int n, m;
  cin >> n >> m;

  ll ans = 0;

  bool toBreak = (m%2 != 0);

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int diff = x2 - x1 + 1;
  if(toBreak) {
    ans += n - diff;
  }

  int leftSize = y1 - 1;
  int rightSize = m - y2;

  if(leftSize%2 != 0) ans += diff;
  if(rightSize%2 != 0) ans += diff;

  cout << ans/2 + ans%2 << endl;

  return 0;
}
