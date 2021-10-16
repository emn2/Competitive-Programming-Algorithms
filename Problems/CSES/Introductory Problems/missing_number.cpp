#include "bits/stdc++.h"
using namespace std;
 
const int nMx = 2*1e5 + 5;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, v[nMx] = {};
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v[a] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(v[i] == 0) {
            cout << i << '\n';
            break;
        }
    }
 
    return 0;
}
