#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    if(n <= k) cout << 2;
    else cout << (int)ceil(2*n/(float)k) << '\n';

    return 0;
}
