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

ld calcTPR(ld truePos, ld falseNeg) {
  return truePos/(truePos + falseNeg);
}

pii calcFTR(int trueNeg, int falsePos) {
  int cur = __gcd(falsePos, trueNeg + falsePos);
  return {falsePos/cur, (trueNeg + falsePos)/cur};
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cout << fixed << setprecision(10);

  // ordered_set positive, negative;
  vector<int> positive, negative;

  map<pii, ld> FTR;

  int n;
  cin >> n;

  char type;
  int val;
  set<int> diffVal;
  for(int i = 0; i < n; ++i) {
    cin >> type;
    cin >> val;

    if(type == '+') {
      positive.PB(val);
    } else {
      negative.PB(val);
    }
    diffVal.insert(val);
  }

  sort(ALL(positive));
  sort(ALL(negative));

  int pSize = positive.size(), nSize = negative.size();

  for(auto i: diffVal) {
    auto it = lower_bound(ALL(positive), i);
    auto it2 = lower_bound(ALL(negative), i);
    
    int truePosQtt = positive.end() - it;
    int falsePosQtt = negative.end() - it2;

    int falseNegQtt = pSize - truePosQtt;
    int trueNegQtt = nSize - falsePosQtt;

    ld tpr = calcTPR(truePosQtt, falseNegQtt);
    pii ftr = calcFTR(trueNegQtt, falsePosQtt);

    FTR[ftr] = max(FTR[ftr], tpr);
  }

  ld curX = -1, curY = -1;

  ld ans = 0;

  vector<pair<ld, ld>> num;

  for(auto i: FTR) {
    num.emplace_back(((ld)i.F.F)/((ld)i.F.S), i.S);
  }

  sort(ALL(num));

  for(auto i: num) {
    if(curX == -1) {
      curX = i.F, curY = i.S;
    } 
    else {
      ans += abs(i.F - curX) * curY;
      curX = i.F, curY = i.S;
    }
  }

  cout << ans << endl;

  return 0;
}
