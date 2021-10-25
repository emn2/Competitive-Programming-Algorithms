#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;

int v[maxn];
ll tree[maxn];

void update(int pos, int n){
      while(pos <= n) {
          tree[pos] += 1;
          pos += pos & (-pos);
      }
}
ll query(int pos){
   ll sum = 0;
   while(pos > 0){
       sum += tree[pos];
       pos -= pos & (-pos);
   }
   return sum;
}

int main(){
    int c = 1;
    while(1){
        ll n, a, b;
        cin >> n >> a >> b;

        if(!n && !a && !b) break;
        for(ll i = 0; i < n; i++){
            v[i]= (a*i+b)%n;
            v[i]++;
        }
        ll ans = 0;
        for(int i = n-1; i >= 0; i--){
            ans += query(v[i]);
            update(v[i],n);
        }
        printf("Case %d: %lld\n", c++, ans);
        memset(tree, 0, sizeof(tree));
    }
    return 0;
}
