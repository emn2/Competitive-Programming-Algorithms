#include "bits/stdc++.h"
using namespace std;
#define int long long
 
const int nMx = 2*1e5 + 5;
int n, v[nMx];
 
int kadane(){
    int max_atual = INT_MIN, max_total = INT_MIN;
 
    for(int i = 0; i < n; i++){
        if(v[i] + max_atual >= v[i]) max_atual += v[i];
        else max_atual = v[i];
        max_total = max(max_total, max_atual);
    }
 
    return max_total;
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    cout << kadane() << '\n';
 
    return 0;
}
