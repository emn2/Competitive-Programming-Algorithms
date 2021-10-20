#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
 
const int MAXN = 1e3 + 10;
const int INF = 0x3f3f3f3f;
 
vector<set<int>> upAdj(MAXN);
int age[MAXN];
int vis[MAXN];
int personInPos[MAXN], curPos[MAXN];
 
int bfs(int source) {
  memset(vis, 0, sizeof vis);
  queue<int> q;
  q.push(source);
 
  vis[source] = true;
  int ans = INF;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
 
    for(auto next: upAdj[cur]) {
      if(vis[next]) continue;
      vis[next] = true;
      q.push(next);
      ans = min(ans, age[personInPos[next]]);
    }
  }
  return ans;
}
 
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;
 
  for(int i = 1; i <= n; ++i) {
    personInPos[i] = i;
    curPos[i] = i;
    cin >> age[i];
  }
 
  int fir, sec;
  for(int i = 0; i < m; ++i) {
    cin >> fir >> sec;
    upAdj[sec].insert(fir);
  }
 
  while(q--) {
    char type;
    cin >> type;
 
    if(type == 'T') {
      cin >> fir >> sec;
 
      swap(personInPos[curPos[fir]], personInPos[curPos[sec]]);
      swap(curPos[fir],  curPos[sec]);
    } else {
      cin >> fir;
      fir = curPos[fir];
      int ans = bfs(fir);
      if(ans == INF) cout << "*" << endl;
      else cout << ans << endl;
    }
  }
 
  return 0;
}
