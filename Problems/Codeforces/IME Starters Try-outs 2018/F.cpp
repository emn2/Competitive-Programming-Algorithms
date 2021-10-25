#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;

//Tree
//posicionar ou nao posicionar
//dp[pai][2] = max(dp[filho][0], dp[filho][1])
//eu tenho duas opcoes por soldado, eu posso adicionalo e nao adicionar seu "filho"
//ou posso nao adiciona-lo e adicionar o seu "filho", meu resultado vai ser o max das
//duas opcoes

int dp[MAXN][2];
vector<vector<int> > adj;

void dfs(int u, int p){
    dp[u][0] = 0, dp[u][1] = 1;
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
        //se eu n pego o U, eu posso pegar ou nao pegar o V
        dp[u][0] += max(dp[v][0], dp[v][1]);
        //se eu pego o U, entao eu nao posso pegar o V
        dp[u][1] += dp[v][0];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';

    return 0;
}
