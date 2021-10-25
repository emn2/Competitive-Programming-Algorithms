#include "bits/stdc++.h"
using namespace std;

#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

const int LIM = 1005;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

bool vis[LIM][LIM];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int s, n, m;

set<iii> mp;
vector<vector<int> > grid;

int bfs(int x, int y, int val){
    int ans = 0;

    queue<ii> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;

    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        ans++;

        for(int i = 0; i < 4; i++){
            int nxt_x = cur_x + dx[i];
            int nxt_y = cur_y + dy[i];

            if(in_range(nxt_x, nxt_y, n, m) && !vis[nxt_x][nxt_y]){
                vis[nxt_x][nxt_y] = true;
                if(grid[nxt_x][nxt_y] >= val) q.push(make_pair(nxt_x, nxt_y));
            }
        }
    }
    return ans;
}

 
bool solve(int val){
    memset(vis, false, sizeof(vis));

    int k = 0;
    auto it = mp.lower_bound(make_pair(val, make_pair(-1, -1)));

    while(it != mp.end()){
        int x = it->second.first;
        int y = it->second.second;

        if(!vis[x][y]) {
            k = bfs(x, y, val);
            if(k >= s) return true;
        }

        it++;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int l, r;
    cin >> s >> n >> m;

    vector<int> v;
    grid.resize(n);

    for(int i = 0; i < n; i++){
        grid[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            v.push_back(grid[i][j]);
            mp.insert(make_pair(grid[i][j], make_pair(i, j)));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    l = 0, r = v.size()-1;

    while(l <= r){
        int mid = (l+r)/2;
        if(solve(v[mid])) l = mid+1;
        else r = mid-1;
    }

    cout << v[r] << '\n';

    return 0;
}
