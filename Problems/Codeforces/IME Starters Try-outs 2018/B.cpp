#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 1005;
const int MAXW = 2005;
const int INF = 1e9;

int t, m;
int dp[MAXN][MAXW];

vector<int> w;
vector<string> resp, mp;

int knapsack(int pos, int total){
    if(dp[pos][total] != -1) return dp[pos][total];
 
    if(total <= 0) return 0;
    if(pos == m) return dp[pos][total] = INF;

    int not_choose = knapsack(pos + 1, total);
    int choose = knapsack(pos + 1, total - w[pos]) + w[pos];
 
    return dp[pos][total] = min(choose, not_choose);
}

void recover_solution(int pos, int total, int remaining){
    if(pos >= m || remaining == 0) return;
    
    // not choose
    if(knapsack(pos+1, total) == remaining) return recover_solution(pos+1, total, remaining);
    // choose
    else {
      resp.push_back(mp[pos]);
      return recover_solution(pos+1, total-w[pos], remaining-w[pos]);
    }
}

int main(){
    int wkit;
    cin >> wkit >> m; 

    int sumTotal = 0;

    w.resize(m);

    int peso;
    string item;
    for(int i = 0; i < m; i++){
        cin >> item >> peso;
        sumTotal += peso;
        mp.push_back(item);
        w[i] = peso;
    }

    memset(dp, -1, sizeof(dp));
    
    int q, peso_menino;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> peso_menino;
        int necessario = (peso_menino + 1)/2 - wkit;
        
        if(necessario <= 0) cout << "0\n";
        else if(necessario > sumTotal) cout << "-1\n";
        else{
            t = knapsack(0, necessario);
            
            if(t == INF) cout << "-1\n";
            else {
              recover_solution(0, necessario, t);
              
              cout << resp.size();
              for(auto e: resp) cout << ' ' << e;
              cout << '\n';
              
              resp.clear();
            }
        }
    }
    return 0;
}
