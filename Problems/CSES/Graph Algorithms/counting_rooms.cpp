#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
#define spid ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int n, m, ans = 0;
vector<string> grid;
 
void bfs(int i, int j, vector<vector<bool> >& vis){
    vector<ii> dir;
    dir.pb(mp(1, 0)), dir.pb(mp(-1, 0)), dir.pb(mp(0, 1)), dir.pb(mp(0, -1));
    queue<ii> q;
    vis[i][j] = true;
    q.push(mp(i, j));
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        for(auto e: dir){
            ii atual;
            atual.x = cur.x + e.x;
            atual.y = cur.y + e.y;
            if(in_range(atual.x, atual.y, n, m) && !vis[atual.x][atual.y] && grid[atual.x][atual.y] != '#'){
                vis[atual.x][atual.y] = true;
                q.push(mp(atual.x, atual.y));
            }
        }
    }
}
 
int main(){
    spid;
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
 
    vector<vector<bool> > vis(n, vector<bool>(m, false));
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                bfs(i, j, vis);
                ans++;
            }
        }
    }
 
    cout << ans << '\n';
 
    return 0;
}
