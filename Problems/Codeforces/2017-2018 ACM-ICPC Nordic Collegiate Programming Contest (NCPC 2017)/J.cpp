#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int l,r;
    cin>>l>>r;
  
    if(l == 0 && r == 0){
      cout<<"Not a moose\n";
    }
    else{
      if(l!=r)cout<<"Odd ";
      else cout<<"Even ";
      cout<<2*max(l,r)<<'\n';
	  }
  
    return 0;
}
