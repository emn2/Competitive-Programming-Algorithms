#include "bits/stdc++.h"
using namespace std;
#define int long long
const int maxn = 5e3 + 5;
const int minint = -1e9 - 2;
 
vector<int> v;
int dp[maxn][maxn][2];
bool calc[maxn][maxn][2] = {};
 
int solve(int l, int r, int turn){
    if(l > r) return 0;
    if(calc[l][r][turn]) return dp[l][r][turn];
    calc[l][r][turn] = 1;
 
    int esq = 0, dir = 0;
 
    if(turn == 0){
        esq = solve(l + 1, r, 1) + v[l];
        dir = solve(l, r - 1, 1) + v[r];
        return dp[l][r][turn] = max(esq, dir);
    }
    else{
        esq = solve(l + 1, r, 0) - v[l];
        dir = solve(l, r - 1, 0) - v[r];
        return dp[l][r][turn] = min(esq, dir);
    }
}
 
int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int n, sum = 0;
  cin >> n;
 
  v.resize(n);
 
  for(int i = 0; i < n; i++){
    cin >> v[i];
    sum += v[i];
  }
 
  cout << (sum + solve(0, n - 1, 0)) / 2 << '\n';
 
  return 0;
}
 
//A + B = soma
//A - B = dp
//____________
//2A = soma + dp -> A = (soma + dp) / 2
