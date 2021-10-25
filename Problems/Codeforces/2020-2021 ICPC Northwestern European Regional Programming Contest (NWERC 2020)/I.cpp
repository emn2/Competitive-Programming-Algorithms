#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n;

bool check(vector<ll>&respX, vector<int>&x, vector<ll>&respY, vector<int>&y){
    for(int i = 0; i < n; i++){
        if(respY[i] >= respX[i] + x[i] || respX[i] >= respY[i] + y[i]) continue;
        else return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<ll> respA(n, 0);
    for(int i = 1; i < n; i++){
        respA[i] = respA[i-1] + d[i-1] + a[i-1];
    }

    vector<vector<ll> > respB(n, vector<ll> (n));
    vector<vector<ll> > respC(n, vector<ll> (n));

    for(int j = 1; j < n; j++){ //tentar encaixar o carinha 2 na atracao j
        for(int i = j+1; i < n; i++){
            respB[j][i] = respB[j][i-1] + d[i-1] + b[i-1];
        }
        respB[j][0] = respB[j][n-1] + d[n-1] + b[n-1];
        for(int i = 1; i < j; i++){
            respB[j][i] = respB[j][i-1] + d[i-1] + b[i-1];
        }
    }

    for(int j = 1; j < n; j++){ //tentar encaixar o carinha 2 na atracao j
        for(int i = j+1; i < n; i++){
            respC[j][i] = respC[j][i-1] + d[i-1] + c[i-1];
        }
        respC[j][0] = respC[j][n-1] + d[n-1] + c[n-1];
        for(int i = 1; i < j; i++){
            respC[j][i] = respC[j][i-1] + d[i-1] + c[i-1];
        }
    }

    for(int i = 1; i < n; i++){         //carinha 2
        for(int j = 1; j < n; j++){     //carinha 3
            if(i == j) continue;
            if(check(respA, a, respB[i], b) && check(respB[i], b, respC[j], c) && check(respA, a, respC[j], c)){
                cout << "1 " << ' ' << i+1 << ' ' << j+1 << '\n';
                return 0;
            }
        }
    }

    cout << "impossible\n";
    return 0;
}
