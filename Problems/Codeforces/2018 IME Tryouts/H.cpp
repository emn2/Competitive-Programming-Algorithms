#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << setprecision(12) << fixed;

    double n, a, p;
    cin >> n >> a >> p;

    cout << (n + a*(p-50)/50) << '\n';

    return 0;
}
