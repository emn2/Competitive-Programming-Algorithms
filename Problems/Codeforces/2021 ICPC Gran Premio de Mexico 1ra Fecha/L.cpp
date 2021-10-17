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

const ll one = 1;
const ll two = 2;

void solve(ll k, string &ans) {
  if(k == 1) {
    ans.PB('2');
    return;
  }
  if(k%2 == 0) {
    ans.PB('(');
    solve(k/two, ans);
    ans.PB(')');
    ans.PB('^');
    ans.PB('2');
  } else {
    ans.PB('(');
    ans.PB('2');
    ans.PB('*');
    solve(k - one, ans);
    ans.PB(')');
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int cases;
  cin >> cases;

  while(cases--) {
    ll n;
    cin >> n;

    string ans = "";
    solve(n, ans);
    cout << ans << endl;
  }

  return 0;
}
