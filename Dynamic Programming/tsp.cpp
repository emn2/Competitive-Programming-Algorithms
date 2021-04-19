ll mask, n, m;
ll dp[1<<LIM][LIM];

ll tsp(int mask, int last){
    if(__builtin_popcountll(mask) == m) return 0;
    if(dp[mask][last] != -1) return dp[mask][last];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i))){
            int new_mask = (mask | (1 << i));
            ans = max(ans, tsp(new_mask, i) + bonus[last][i] + v[i]);
        }
    }
    return dp[mask][last] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
  
    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, tsp(1<<i, i));
    }
    cout << ans << '\n';

    return 0;
}
