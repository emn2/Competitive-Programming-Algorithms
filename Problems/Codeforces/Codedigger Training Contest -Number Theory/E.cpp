#include "bits/stdc++.h"
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, a, b, c;
        vector<int> v;
        cin >> x;
        cin >> a >> b >> c;
        v.push_back(c + x);
        for(int n = 2; n*n <= x; n++){
            if(x % n == 0){
                if(isPrime(n)) v.push_back(a + (x/n));     
                else v.push_back(b + (x/n));

                if(isPrime(x/n)) v.push_back(a + n);
                else v.push_back(b + n);
            }
        }
        sort(v.begin(), v.end());
        cout << v[0] << '\n';
        v.clear();
    }

    return 0;
}
