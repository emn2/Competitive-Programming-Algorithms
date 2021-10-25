#include "bits/stdc++.h"
using namespace std;
#define int long long

int gcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    while(q--){
        int c, d, x, y;
        cin >> c >> d;

        int voltas = c/n;
        int resto = c%n;

        int inverso = gcd(k, n, x, y);

        x *= d;
        x = (x % n + n) % n;

        if(resto == 0){
            cout << voltas << '\n';
        }
        else{
           if(resto > x) voltas++;
           cout << voltas << '\n';
        }
    }

    return 0;
}
