#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int p, ans, sBit = 1e9 + 1, cnt = 100;
        cin >> p;
        vector<int> v;
        for(int i = 0; i < p; i++){
            int a; 
            cin >> a;
            v.push_back(a);
        }
        for(int i = 0; i < p; i++){
          int aux = v[i], prov = 0;
            while((aux % 2) != 1){
              aux = aux >> 1;
              prov++;
            }
            cnt = min(prov, cnt);
        }
        ans = v[0];
        for(int i = 1; i < p; i++){
            ans ^= v[i];
        }
        if(ans != 0) cout << '0' << '\n';
        else {
            cout << pow(2, cnt) << '\n';
        }
        v.clear();
    }

    return 0;
}
