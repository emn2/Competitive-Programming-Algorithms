#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int t;
    cin >> t;
    while(t--){
      long long x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      
      if(abs(x1-x2) > abs(y1-y2)){
        swap(x1,y1);
        swap(x2,y2);
      }
      
      long long ans = 2 * abs(x2-x1);
      long long dy = abs(y2 - y1) - abs(x2 - x1);
      ans += 4 * (dy/2);
      dy %= 2;
      if(dy == 1) ++ans;
      cout << ans << '\n';
    }
    return 0;
}
