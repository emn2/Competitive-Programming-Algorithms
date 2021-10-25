#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

char board[8][8];
int grid[8][8];

int ans = 0;

bool isValid(int x, int y) {
  if(x < 0 || x >= 8 || y < 0 || y >= 8 || grid[x][y] != 0) return false;
  return true;
}

int kingMovesX[] = {1, 0, -1, 1, -1, 1, 0, -1};
int kingMovesY[] = {1, 1, 1, 0, 0, -1, -1, -1};

int horseMovesX[] = {2, -2, 1, -1, 2, -2, 1, -1};
int horseMovesY[] = {1, 1, 2, 2, -1, -1, -2, -2};

void checkTower(int x, int y) {
  //up
  for(int i = x - 1; i >= 0; --i) {
    if(grid[i][y] == 1) break;
    if(grid[i][y] != 2) {
      --ans;
      grid[i][y] = 2;
    }
  }
  //down
  for(int i = x + 1; i < 8; ++i) {
    if(grid[i][y] == 1) break;
    if(grid[i][y] != 2) {
      --ans;
      grid[i][y] = 2;
    }
  }
  //right
  for(int i = y + 1; i < 8; ++i) {
    if(grid[x][i] == 1) break;
    if(grid[x][i] != 2) {
      --ans;
      grid[x][i] = 2;
    }
  }
  //left
  for(int i = y - 1; i >= 0; --i) {
    if(grid[x][i] == 1) break;
    if(grid[x][i] != 2) {
      --ans;
      grid[x][i] = 2;
    }
  }
}

void checkKnight(int x, int y) {
  for(int i = 0; i < 8; ++i) {
    int nx = x + horseMovesX[i], ny = y + horseMovesY[i];
    if(isValid(nx, ny))  {
      --ans;
      grid[nx][ny] = 2;
    }
  }
}

void checkBishop(int x, int y) {
  //up left
  for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
    if(grid[i][j] == 1) break;
    if(grid[i][j] != 2) {
      --ans;
      grid[i][j] = 2;
    }
  }
  //up right
  for(int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j) {
    if(grid[i][j] == 1) break;
    if(grid[i][j] != 2) {
      --ans;
      grid[i][j] = 2;
    }
  }
  //down left
  for(int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j) {
    if(grid[i][j] == 1) break;
    if(grid[i][j] != 2) {
      --ans;
      grid[i][j] = 2;
    }
  }
  //down right
  for(int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j) {
    if(grid[i][j] == 1) break;
    if(grid[i][j] != 2) {
      --ans;
      grid[i][j] = 2;
    }
  }
}

void checkQueen(int x, int y) {
  checkTower(x, y);
  checkBishop(x, y);
}

void checkKing(int x, int y) {
  for(int i = 0; i < 8; ++i) {
    int nx = x + kingMovesX[i], ny = y + kingMovesY[i];
    if(isValid(nx, ny)) {
      --ans;
      grid[nx][ny] = 2;
    }
  }
}

void checkWhitePawn(int x, int y) {
  if(x == 0) return;
  if(y != 0 && !grid[x - 1][y - 1]) {
    --ans;
    grid[x - 1][y - 1] = 2;
  }
  if(y != 7 && !grid[x - 1][y + 1]) {
    --ans;
    grid[x - 1][y + 1] = 2;
  }
}

void checkBlackPawn(int x, int y) {
  if(x == 7) return;
  if(y != 0 && !grid[x + 1][y - 1]) {
    --ans;
    grid[x + 1][y - 1] = 2;
  }
  if(y != 7 && !grid[x + 1][y + 1]) {
    --ans;
    grid[x + 1][y + 1] = 2;
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);


  string pieces;
  while(getline(cin, pieces)) {
    ans = 0;

    memset(grid, 0, sizeof grid);
    for(int i = 0; i < 8; ++i) for(int j = 0; j < 8; ++j) board[i][j] = '.';

    int row = 0;
    int col = 0;
    for(int i = 0; i < pieces.size(); ++i) {
      if(pieces[i] == '/') {
        ++row;
        col = 0;
      } else if(pieces[i] == 'r' || pieces[i] == 'R') {
        board[row][col] = 'R';
        grid[row][col] = 1;
        ++col;
      } else if(pieces[i] == 'k' || pieces[i] == 'K') {
        board[row][col] = 'K';
        grid[row][col] = 1;
        ++col;
      } else if(pieces[i] == 'n' || pieces[i] == 'N') {
        board[row][col] = 'N';
        grid[row][col] = 1;
        ++col;
      } else if(pieces[i] == 'b' || pieces[i] == 'B') {
        board[row][col] = 'B';
        grid[row][col] = 1;
        ++col;
      } else if(pieces[i] == 'q' || pieces[i] == 'Q') {
        board[row][col] = 'Q';
        grid[row][col] = 1;
        ++col;
      } else if(pieces[i] == 'p') {
        board[row][col] = 'p';
        grid[row][col] = 1;
        ++col;
      } else if(pieces[i] == 'P') {
        board[row][col] = 'P';
        grid[row][col] = 1;
        ++col;
      } else {
        col += pieces[i] - '0';
        ans += pieces[i] - '0';
      }
    }

    for(int i = 0; i < 8; ++i) {
      for(int j = 0; j < 8; ++j) {
        if(board[i][j] == 'R') {
          checkTower(i, j);
        } else if(board[i][j] == 'K') {
          checkKing(i, j);
        } else if(board[i][j] == 'B') {
          checkBishop(i, j);
        } else if(board[i][j] == 'Q') {
          checkQueen(i, j);
        } else if(board[i][j] == 'p') {
          checkBlackPawn(i, j);
        } else if(board[i][j] == 'P') {
          checkWhitePawn(i, j);
        } else if(board[i][j] == 'N') {
          checkKnight(i, j);
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
