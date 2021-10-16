#include "bits/stdc++.h"
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, prov = 0;
    string code;
    getline(cin, code);
    for(int i = 1; i < code.size(); i++){
        if(code[i] == code[i - 1]) prov++;
        else {
            ans = max(ans, prov + 1);
            prov = 0;
        }
    }
    ans = max(ans, prov + 1);
    cout << ans << '\n';
    return 0;
}
