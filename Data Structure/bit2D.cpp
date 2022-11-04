const int MAXN = 2005;

int BIT[MAXN][MAXN];

void update(int x, int y){
    for( ; x < MAXN; x += (x & -x)){
        for(int yy = y; yy < MAXN; yy += (yy & -yy))
            BIT[x][yy]++;
    }
}

int query(int x, int y){
    int sum = 0;
    for( ; x > 0; x -= (x & -x)){
        for(int yy = y; yy > 0; yy -= (yy & -yy)){
            sum += BIT[x][yy];
        }
    }
    return sum;
}

int ans(int x1, int y1, int x2, int y2){
  return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}
