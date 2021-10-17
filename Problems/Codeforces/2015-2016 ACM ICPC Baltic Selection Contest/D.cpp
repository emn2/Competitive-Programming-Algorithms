#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1e11;
typedef pair<int, int> ii;
typedef pair<ll, pair<int, int> > iii;
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

int n, m, a, b;
vector<ii> dir;
vector<string> grid;

ll bfs(){
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(mp(0, mp(0, 0)));
    vis[0][0] = true;
    while(!q.empty()){
        iii cur = q.top();
        q.pop();
        if(cur.y.x == n-1 && cur.y.y == m-1) return cur.x;
        for(auto e: dir){
            iii next = cur;
            next.y.x += e.x; next.y.y += e.y;
            if(in_range(next.y.x, next.y.y, n, m) && !vis[next.y.x][next.y.y] && grid[next.y.x][next.y.y] != '#'){
                vis[next.y.x][next.y.y] = true;
                next.x++;
                q.push(next);
            }
        }
    }
    if(!vis[n-1][m-1]) return INF;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> a >> b;

    grid.resize(n);
    for(int i = 0; i < n; i++) cin >> grid[i]; 

    dir.pb(mp(-1, 0)); dir.pb(mp(1, 0));
    dir.pb(mp(0, -1)); dir.pb(mp(0, 1));

    ll ans = bfs();

    if(ans == INF) cout << "IMPOSSIBLE\n";
    else {
        if(ans % 2 == 0) cout << (ans/2)*(a + b);
        else cout << b*(ans/2 + 1) + a*(ans/2);
    }

    return 0;
}
