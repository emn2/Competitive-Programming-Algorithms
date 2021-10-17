#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);
    int r,c;
    cin>>r>>c;
      vector<vector<int>>g(r,vector<int>(c));
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
        cin>>g[i][j];

    int ans = 0;
    for(int i=0;i<r;++i){
      vector<int>maxR(c);
      for(int j=c-2;j>=0;--j)
        maxR[j] = max(maxR[j+1],g[i][j+1]);
      int maxL = 0;
      for(int j=0;j<c;++j){
        if(maxL < g[i][j])++ans;
        if(maxR[j] < g[i][j])++ans;
        maxL = max(maxL, g[i][j]);
      }
    }
    for(int j=0;j<c;++j){
      vector<int>maxR(r);
      for(int i=r-2;i>=0;--i)
        maxR[i] = max(maxR[i+1],g[i+1][j]);
      int maxL = 0;
      for(int i=0;i<r;++i){
        if(maxL < g[i][j])++ans;
        if(maxR[i] < g[i][j])++ans;
        maxL = max(maxL, g[i][j]);
      }
    }
    cout<<ans<<'\n';

    return 0;
}
