#include "bits/stdc++.h"
using namespace std;

#define int long long

bool fatorar(int n){
    int aux = n;
    int cnt = 0;
    while(aux % 2 == 0){
        aux /= 2;
        cnt++;
        if(cnt > 1) return false;
    }
    for(int i = 3; i*i <= aux; i+=2){
        cnt = 0;
        while(aux % i == 0){
            aux /= i;
            cnt++;
            if(cnt > 1) return false;
        }
    }
    if(aux == n || n == 2) return false;
    return true;
}

int divs(int n){
    vector<int> divisors;
    divisors.push_back(n);
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(i != n/i) divisors.push_back(n/i);
        }
    }
    int ans = 0;
    for(auto e: divisors){
        if(fatorar(e)) ans++;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << divs(n) << '\n';
}
