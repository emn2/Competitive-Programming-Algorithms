long long sum(int i1, int j1, int i2, int j2){
  long long res = dp[i2][j2];
  if(i1 >= 1) res -= dp[i1 - 1][j2];
  if(j1 >= 1) res -= dp[i2][j1 - 1];
  if(i1 >= 1 && j1 >= 1) res += dp[i1 - 1][j1 - 1];
  return res;
}

int main(){
  vector<vector<int>> v;
  vector<vector<long long>> dp;

  dp[0][0] = v[0][0];
  for(int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + v[i][0];
  for(int j = 1; j < m; j++) dp[0][j] = dp[0][j - 1] + v[0][j];

  for(int i = 1; i < n; i++)
    for(int j = 1; j < m; j++)
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j];
}
