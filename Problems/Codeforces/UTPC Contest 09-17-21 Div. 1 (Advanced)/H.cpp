#include "bits/stdc++.h"
using namespace std;

#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

const int MAXN = 505;
const int INF = 1e9 + 5;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int grid[MAXN][MAXN];

void bfs(){
    vector<vector<int> > d(n, vector<int> (n, INF));
    vector<vector<bool> > vis(n, vector<bool> (n, false));

    d[0][0] = 0;
    vis[0][0] = true;

    deque<pair<int, int> > q;

    q.push_front(make_pair(0, 0));

    while (!q.empty()) {
        int vx = q.front().first;
        int vy = q.front().second;

        q.pop_front();

        if(vx == n-1 && vy == n-1){
            cout << d[vx][vy] << '\n';
            return;
        }

        for(int i = 0; i < 4; i++){
            if(in_range(vx + dx[i], vy + dy[i], n, n)){
                int ux = vx + dx[i];
                int uy = vy + dy[i];
                int w = grid[ux][uy];

                if(d[vx][vy] + w < d[ux][uy] && !vis[ux][uy]){
                    vis[vx][vy] = true;
                    d[ux][uy] = d[vx][vy] + w;
                    if(w == 1) q.push_back(make_pair(ux, uy));
                    else q.push_front(make_pair(ux, uy));
                }
            }
        }
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            grid[i][j] = 1 - (s[j] - '0');
        }
    }

    bfs();

    return 0;
}
