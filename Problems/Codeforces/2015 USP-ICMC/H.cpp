#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, pair<ll, ll> > pll;
const ll INF = 1e18+5;
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n-1); i >= 0; i--)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll valor[30][30], ans = 0, n;

    forc(i, 26){
        forc(j, 26){
            cin >> valor[i][j];
        }
        valor[i][i] = 0;
    }

    forc(k, 26){
        forc(i, 26){
            forc(j, 26){
                valor[i][j] = min(valor[i][j], valor[i][k] + valor[k][j]);
            }
        }
    }
    cin.ignore();
    string s;
    getline(cin, s);
    n = s.size();

    forc(i, n/2){
        ll dist = INF;
        int x = (s[i] - 'a'), y = (s[n-i-1] - 'a');
        forc(j, 26){
            if(dist > valor[x][j] + valor[y][j]){
                dist = valor[x][j] + valor[y][j];
            }
        }
        ans += dist;
    }

    cout << ans << '\n';
   
    return 0;
}
