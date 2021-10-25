#include "bits/stdc++.h"
using namespace std;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   int n, s;
   cin >> n >> s;
   map<int, int> mp;

   for(int i = 0; i < n; i++){
       int a; cin >> a;
       mp[a]++;
   }
   bool ans = true;
   for(auto e: mp){
       int num = e.first;
       int qntd = e.second;
       if(2*num == s && qntd > 2) ans = false;
   }
   if(ans) cout << "yes\n";
   else cout << "no\n";
   return 0;
}
