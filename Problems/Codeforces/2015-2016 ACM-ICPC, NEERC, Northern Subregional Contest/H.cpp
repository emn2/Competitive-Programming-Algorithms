#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
	  freopen("hash.in","r",stdin);
	  freopen("hash.out","w",stdout);
  
	  int k;
    cin>>k;
  
	  string ans(k,'a');
	  cout<<ans<<'\n';
  
	  k--;
	  for(int i=0;i<k;++i){
		  cout<<ans.substr(0,i)<<"bB"<<ans.substr(i+2)<<'\n';
	  }
  
    return 0;
}
