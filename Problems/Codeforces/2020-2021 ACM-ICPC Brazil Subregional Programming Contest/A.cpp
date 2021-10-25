#include<bits/stdc++.h>
using namespace std;
const int ms = 1e6 + 10;
double dp[ms],acc[ms];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n, a, b;
    cin >> n >> a >> b;
    double d = b - a + 1;
  
    for(int i = 1, l = i - b, r = i - a; i <= n; ++i,++l,++r){
      if(a == 0){
        double dpsum = acc[i - 1] - (l - 1 >= 0 ? acc[l - 1] : 0);
        dp[i] = (dpsum + 1)/(1.0*b) + 1;
      }
      else{
        double dpsum = (r >= 0 ? acc[r] : 0) - (l - 1 >= 0 ? acc[l - 1] : 0);
        dp[i] = dpsum/d + 1;
      }
      acc[i] = acc[i - 1] + dp[i];
    }
  
    cout << setprecision(12) << fixed << dp[n] << '\n';
  
    return 0;
}
