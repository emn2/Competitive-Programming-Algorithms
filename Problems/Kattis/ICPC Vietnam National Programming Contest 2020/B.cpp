#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int dx[8] = {1,1,0,-1,-1,-1,0,1};
const int dy[8] = {0,-1,-1,-1,0,1,1,1};

int n, m;
vector<string> g;

int bfs(vector<pair<int,int>>& start){
	vector<vector<int>> dist(n+2, vector<int>(m+2, inf));
	deque<pair<int,int>>q;
  
	for(auto [x,y] : start){
		q.push_front({x,y});
		dist[x][y] = 0;
	}
	
	while(!q.empty()){
		auto [x,y] = q.front();
		q.pop_front();
		for(int d = 0; d < 8; ++d){
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1 || g[nx][ny] == '@')continue;
			if(g[x][y] == '*' && g[nx][ny] == '*') continue;
			int custo = g[nx][ny] == '.';
			if(dist[nx][ny] > dist[x][y] + custo){
				dist[nx][ny] = dist[x][y] + custo;
				if(custo)q.push_back({nx,ny});
				else q.push_front({nx,ny});
			}
		}
	}
  
	int ans = inf;
	for(int j = 1; j <= m; ++j) ans = min(ans, dist[n+1][j]);
	for(int i = 1; i <= n; ++i) ans = min(ans, dist[i][0]);
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    while(cin>>n>>m){
      if(n == 0)break;
      
      g.assign(n + 2,string(m+2,'*'));
      
      for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
          cin >> g[i][j];

      vector<pair<int,int>>topo;
      vector<pair<int,int>>direita;
      
      for(int j = 0; j <= m+1; ++j)
        topo.emplace_back(0, j);
      
      for(int i = 0; i <= n+1; ++i)
        direita.emplace_back(i, m+1);
      
      int ans = min(bfs(topo), bfs(direita));
      
      if(ans == inf) ans = -1;

      cout << ans << '\n';
    }
  
    return 0;
}
