#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        cin.ignore();
        string dir;
        getline(cin, dir);
        string resp = "ESWN";
        for(auto e: dir){
            if(e == '0') ans += 1;
            else ans -= 1;
        }
        int mod = (((ans % 4) + 4) % 4);
        cout << resp[mod] << '\n';
    }

    return 0;
}
