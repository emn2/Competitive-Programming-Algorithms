#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e3 + 5;

int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

int moveX[] = {0, 1, 0, -1};
int moveY[] = {-1, 0, 1, 0};

bool isValid(int x, int y) {
  if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || grid[x][y] == 'X') return false;
  return true;
}

void bfs(int sx, int sy) {
  queue<pii> next;
  next.emplace(sx, sy);
  dist[sx][sy] = 0;

  while(!next.empty()) {
    auto cur = next.front(); next.pop();
    int x = cur.F, y = cur.S;

    for(int i = 0; i < 4; ++i) {
      int nx = x + moveX[i], ny = y + moveY[i];
      if(isValid(nx, ny)) {
        if(dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            next.emplace(nx, ny);
        }
      }
    }
  }
}

char solve(int x, int y) {
  if(grid[x][y] == '#') return 'W'; 
  if(grid[x][y] == 'X') return 'X'; 
  if(grid[x][y] == 'E') return 'E'; 
  if(dist[x][y] == -1) return '?';

  int curDist = dist[x][y];
  int move = 0;
  for(int i = 0; i < 4; ++i) {
    int nx = x + moveX[i], ny = y + moveY[i];
    if(isValid(nx, ny)) {
      if(dist[nx][ny] < curDist) {
        curDist = dist[nx][ny];
        move = i;
      }
    }
  }

  switch (move) {
    case 0: return 'L';
      break;
    case 1: return 'D';
      break;
    case 2: return 'R';
      break;
    case 3: return 'U';
      break;
  }

  return '?';
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;  

  int sx, sy;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if(grid[i][j] == 'E') {
        sx = i, sy = j;
      }
    }
  }

  memset(dist, -1, sizeof dist);
  bfs(sx, sy);

  int queries;
  cin >> queries;


  while(queries--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    cout << solve(i, j) << endl;
  }

  return 0;
}
