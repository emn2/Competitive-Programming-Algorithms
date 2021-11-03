#include "bits/stdc++.h"
using namespace std;
#define int long long

const int maxn = 105;
const int maxw = 1e5 + 5;

int n, capacity;
int dp[maxn][maxw];
vector<int> price;
vector<int> weight;

int knapsack(int pos, int total){
    if(dp[pos][total] != -1) return dp[pos][total];

    if(pos == n) return 0;
    if(total > capacity) return 0;

    int choose = 0;
    int not_choose = knapsack(pos + 1, total);

    if(weight[pos] + total <= capacity){
        choose = knapsack(pos + 1, total + weight[pos]) + price[pos]; 
    }
    return dp[pos][total] = max(choose, not_choose);
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> n >> capacity;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        weight.push_back(a);
        price.push_back(b);
    }

    cout << knapsack(0, 0) << '\n';
}
