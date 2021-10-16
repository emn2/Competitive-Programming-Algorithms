#include "bits/stdc++.h"
using namespace std;
 
const int LIM = 2e5;
int N, t[LIM << 1];
 
void build(){
  for (int i = N - 1; i; i--)
    t[i] = min(t[i << 1], t[i << 1 | 1]);
}
 
int query(int l, int r){
  int res = 1e9 + 7;
  for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1){
    if (l & 1)
      res = min(res, t[l++]);
    if (r & 1)
      res = min(res, t[--r]);
  }
  return res;
}
 
int main(){
  int q;
  cin >> N >> q;
  for (int i = 0; i < N; i++)
    cin >> t[i + N];
  build();
 
  for (int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << query(a, b) << '\n';
  }
 
  return 0;
}
