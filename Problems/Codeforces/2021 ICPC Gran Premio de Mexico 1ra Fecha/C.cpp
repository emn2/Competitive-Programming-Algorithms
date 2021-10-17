#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e6 + 5;

int qntdPrime[MAXN], isPrime[MAXN];

void crivo(){
    for(int i = 0; i < MAXN; i++) isPrime[i] = 1;

    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < MAXN; i++){
        if(isPrime[i]){
            for(int j = i*2; j < MAXN; j += i){
                isPrime[j] = 0;
            }
        }
    }

    memset(qntdPrime, 0, sizeof(qntdPrime));
    for(int i = 2; i < MAXN; i++){
        qntdPrime[i] = qntdPrime[i-1] + isPrime[i];
    }
}

int solve(int l, int r){
    int ans = qntdPrime[r] - qntdPrime[l];
    if(isPrime[l]) ans++;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    crivo();

    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }

    return 0;
}
