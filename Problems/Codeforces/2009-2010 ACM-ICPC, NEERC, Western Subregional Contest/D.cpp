#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;


int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    freopen("dales.in", "r", stdin);
    freopen("dales.out", "w", stdout);
    
    int n,t;
    cin>>t;

    while(t--){
      cin>>n;
      
      int arr[n+10]={};
      int lef[n+10]={};
      int rig[n+10]={};

      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      //hill
      for(int i=1;i<n;i++){
        //cout<<arr[i]<<" "<<arr[i-1]<<endl;
        if(arr[i]>arr[i-1]){
          lef[i]=lef[i-1]+1;
        }
        else lef[i] = 0;
      }

      for(int i=n-2;i>-1;i--){
        if(arr[i]>arr[i+1]){
          rig[i]=rig[i+1]+1;
        }
        else rig[i] = 0;
      }

      int ans = 0;

      for(int i=1;i<n-1;i++){
        int mini = min(lef[i],rig[i]);
        if(mini>ans)ans = mini;
      }
      int hill = ans;

      memset(lef,0,sizeof lef);
      memset(rig,0,sizeof rig);

      for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
          lef[i]=lef[i-1]+1;
        }
        else lef[i] = 0;
      }

      for(int i=n-2;i>-1;i--){
        if(arr[i]<arr[i+1]){
          rig[i]=rig[i+1]+1;
        }
        else rig[i] = 0;
      }
      ans = 0;
      int dale; 

      for(int i=1;i<n-1;i++){
        int mini = min(lef[i],rig[i]);
        if(mini>ans)ans = mini;
      }

      dale = ans;

      cout<<hill<<" "<<dale<<endl;
    }

    return 0;
}
