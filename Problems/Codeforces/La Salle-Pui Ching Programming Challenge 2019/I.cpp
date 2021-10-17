#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int n = 100;
const int m = 6;

int id(int x, int y){
	return x * m + y;
}

pair<int,int> get(int a){
	return {a/m,a%m};
}

int dist(int id1, int id2){
	int x1 = id1/m;
	int y1 = id1%m;

	int x2 = id2/m;
	int y2 = id2%m;

	return abs(x1-x2) + abs(y1-y2);
}

vector<vector< pair<int,int> > >adj;
int pos[n + 2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 20 x 6
    int xo = 7, yo = 0;
    int xp = 12, yp = 0;
    int sorvete = 1;
    for(int i=6;i>=0;--i){
      pos[sorvete] = pos[sorvete + 1] = id(i,0);
      sorvete += 2;
    }
    for(int j=0;j<m;++j){
      pos[sorvete] = pos[sorvete + 1] = id(0,j);
      sorvete += 2;
    }
    for(int i=0;i<20;++i){
      pos[sorvete] = pos[sorvete + 1] = id(i,m-1);
      sorvete += 2;
    }
    for(int j=m-1;j>=0;--j){
      pos[sorvete] = pos[sorvete + 1] = id(19,j);
      sorvete += 2;
    }
    for(int i=19;i>xo;--i){
      if(i == xp)continue;
      pos[sorvete] = pos[sorvete + 1] = id(i,0);
      sorvete += 2;
    }
    pos[0] = id(xo,yo);
    pos[n+1] = id(xp,yp);

    vector<int>ord(10);
    for(int &x : ord){
      cin>>x;
      x = pos[x];
    }
    sort(begin(ord),end(ord));
    int ans = inf;
    do{
      int tmp = 0;
      int st = pos[0];
      int ed = pos[n+1];
      for(int x : ord){
        tmp += dist(x,st);
        st = x;
      }
      tmp += dist(st,ed);
      ans = min(ans, tmp);
    }while(next_permutation(begin(ord),end(ord)));
  
    cout<<ans<<'\n';
  
    return 0;
}
