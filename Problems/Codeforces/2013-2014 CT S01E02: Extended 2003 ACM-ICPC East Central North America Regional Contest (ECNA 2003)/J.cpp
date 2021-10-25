#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef double ld;
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

  string a, b;
  while(getline(cin, a)) {
    getline(cin, b);

    string ans = "";
    for(int i = 0; i < a.size(); ++i) {
      for(int j = 0; j < b.size(); ++j) {
        if(a[i] == b[j]) {
          ans.PB(a[i]);
          b[j] = '#';
          break;
        }
      } 
    }

    sort(ALL(ans));

    cout << ans << endl;
  }

  return 0;
}
