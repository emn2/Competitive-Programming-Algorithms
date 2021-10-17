#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin>>x>>y;
    int ans = 0;
    vector<int>p(101);
    for(int z=1;z<=100;++z){
      for(int w = 1;w<=100;++w){
        p[z] += abs(w-z) < abs(w-x) && abs(w-z) < abs(w-y) ? 1 : 0;
      }
      if(p[z] > p[ans])ans = z;
    }
    cout<<ans<<'\n';
    return 0;
}
