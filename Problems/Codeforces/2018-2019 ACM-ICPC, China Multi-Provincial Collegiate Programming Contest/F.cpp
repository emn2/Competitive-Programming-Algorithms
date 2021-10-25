#include "bits/stdc++.h"
using namespace std;
const int LIM = 205;
typedef long long ll;
const ll INF = 1e18 + 5;
typedef pair<int, int> ii;
#define mp(a, b) make_pair(a, b)
#define grafo vector<vector<int> >
#define forc(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n-1); i >= 0; i--)

int n, q;
vector<ii> v;
ll dp[LIM][LIM][LIM];
vector<int> risk, ordem;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for(int h = 1; h <= t; h++){
        cin >> n >> q;
        risk.resize(n+5);
        ordem.resize(n+5);
        memset(dp, INF, sizeof(dp));
        for(int i = 1; i <= n; i++){
            cin >> risk[i];
            v.push_back(mp(risk[i], i));
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> dp[0][i][j];
            }
        }
        sort(v.begin(), v.end());
        sort(risk.begin() + 1, risk.begin()+1+n);
        for(int i = 1; i <= n; i++) ordem[i] = v[i-1].second;

        for(int k = 1; k <= n; k++){
            int m = ordem[k];
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][m]+dp[k-1][m][j]);
                }
            }
        }
        cout << "Case #" << h << ":\n";
        while(q--){
            int x, y, w;
            cin >> x >> y >> w;
            int perigo = upper_bound(risk.begin()+1, risk.begin()+1+n, w) - risk.begin();
            perigo--;
            cout << dp[perigo][x][y] << '\n';
        }
        v.clear();
    }

    return 0;
}
