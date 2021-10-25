#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, qntdImpar = 0, qntdPar = 0;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i]%2 == 1) qntdImpar++;
            else qntdPar++;
        }
        if(qntdImpar == 0) cout << "-1\n";
        else{
            cout << qntdPar << '\n';
        }
    }

    return 0;
}
