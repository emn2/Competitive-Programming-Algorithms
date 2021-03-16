#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define max(a, b) ((a > b) ? a : b)
#define forc(i, n) for(int i = 0; i < int(n); i++)

int n;
vector<ll> temp;
vector<vector<int> > M;

ll kadane2D(){
    int local_start, start, finish = -1;
    ll sum = 0, maxSum = INT64_MIN;
    for(int i = 0; i < n; i++){
        sum += temp[i];
        if(sum < 0) {
            sum = 0;
            local_start = i+1;
        }
        else if(sum > maxSum) {
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }

    if(finish != -1) return maxSum;

    //Todos os nums sao negativos
    maxSum = temp[0];
    for(int i = 1; i < n; i++)
        maxSum = max(temp[i], maxSum);
    return maxSum;
}

void solve(){
    ll maxSum = INT64_MIN;
    forc(l, n){
        temp.assign(n, 0);
        for(int r = l; r < n; r++){
            for(int i = 0; i < n; i++)
                temp[i] += M[i][r];
            ll sum = kadane2D();
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    M.resize(n, vector<int> (n));
    
    for(auto &e: M)
        for(auto &a: e) 
            cin >> a;

    solve();

    return 0;
}
