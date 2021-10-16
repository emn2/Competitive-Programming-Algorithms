#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef pair<char, ii> cii;
typedef pair<string, ii> sii;
#define x first
#define y second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
#define spid ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int n, m;
bool achou = false;
vector<string> grid;
vector<vector<char> > ans(n, vector<char>(m));
 
void rebuild(int i, int j){
    string resp = "";
    while(grid[i][j] != 'A'){
        resp += ans[i][j];
        if(ans[i][j] == 'R') j--;
        else if(ans[i][j] == 'L') j++;
        else if(ans[i][j] == 'U') i++;
        else i--;
    }
    reverse(resp.begin(), resp.end());
    cout << "YES\n" << resp.length() << '\n' << resp << '\n';
}
 
void bfs(int i, int j){
    queue<cii> q;
    vector<cii> dir;
    ans.assign(n, vector<char>(m, '#'));
    vector<vector<bool> > vis(n, vector<bool>(m, false));
 
    dir.pb(mp('D', mp(1, 0))), dir.pb(mp('U', mp(-1, 0))), dir.pb(mp('R', mp(0, 1))), dir.pb(mp('L', mp(0, -1)));
 
    vis[i][j] = true;
    q.push(mp('#', mp(i, j)));
 
    while(!q.empty()){
        cii cur = q.front();
        q.pop();
        for(auto e: dir){
            cii atual;
            atual.x = e.x;
            atual.y.x = cur.y.x + e.y.x;
            atual.y.y = cur.y.y + e.y.y;
            if(in_range(atual.y.x, atual.y.y, n, m) && !vis[atual.y.x][atual.y.y] && grid[atual.y.x][atual.y.y] != '#'){
                vis[atual.y.x][atual.y.y] = true;
                ans[atual.y.x][atual.y.y] = atual.x;
                q.push(atual);
                if(grid[atual.y.x][atual.y.y] == 'B'){
                    achou = true;
                    rebuild(atual.y.x, atual.y.y);
                    break;
                }
            }
        }
    }
    if(!achou) cout << "NO\n";
}
 
int main(){
    spid;
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A') {
                bfs(i, j);
                break;
            }
        }
    }
 
    return 0;
}
