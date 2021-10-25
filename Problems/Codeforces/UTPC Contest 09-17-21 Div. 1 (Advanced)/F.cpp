#include "bits/stdc++.h"
using namespace std;

int resp = 0;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(int n){
    int aux = n;
    int max_expo = 0;
    map<int, int> expo;
    for(int i = 2; i <= n; i++){
        int cnt = 0;
        while(aux % i == 0 && aux > 0){
            aux /= i;
            cnt++;
        }
        if(cnt != 0) {
            expo[i] = cnt;
            max_expo = max(max_expo, cnt);
        }
    }
    int ans_agora = 1;
    for(int p = 2; p <= max_expo; p++){
        ans_agora = 1;
        for(auto e: expo){
            int qntd = e.second/p;
            ans_agora *= pow(e.first, qntd*p);
        }
        resp = max(resp, ans_agora);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int gcd_total = a[0];

    for(int i = 1; i < n; i++) gcd_total = gcd(gcd_total, a[i]);

    solve(gcd_total);
    
    if(resp < 4) cout << "NO CIVIL WAR\n";
    else cout << resp << '\n';

    return 0;
}
