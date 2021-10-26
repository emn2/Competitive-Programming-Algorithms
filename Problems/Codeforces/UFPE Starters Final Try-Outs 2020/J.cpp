#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int LIM = 1e5 + 5;
const int INF = 1e9 + 5;

ll dp[LIM][7];
vector<vector<ii> > adj;

ll solve(int u, int p, int last){
    if(adj[u].size() == 1 && adj[u][0].first == p) return 1LL;

    if(dp[u][last] != -1) return dp[u][last];

    ll ans = 0LL;

    for(int i = 1; i < (1 << 5); i++){
        if(__builtin_popcount(i) != adj[u].size()) continue;

        vector<int> color;
        for(int j = 0; j < 5; j++)
            if(i & (1 << j)) color.push_back(j + 1);

        do{
            ll cnt = 1LL;
            bool isPossible = true;

            for(int j = 0; j < adj[u].size() && isPossible; j++){
                int v = adj[u][j].first;
                int c = adj[u][j].second;

                if(v == p && color[j] != last) isPossible = false;
                else if(v != p){
                    if(c && c != color[j]) isPossible = false;
                    else cnt = (cnt * solve(v, u, color[j])) % MOD;
                }
            }

            if(!isPossible) continue;
            ans = (ans + cnt) % MOD;

        } while(next_permutation(color.begin(), color.end()));
    }

    return dp[u][last] = ans;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    adj.resize(n+5);

    memset(dp, -1LL, sizeof(dp));

    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    if(n == 1) cout << 1 << '\n';
    else cout << solve(0, -1, 6) << '\n';
    
}
