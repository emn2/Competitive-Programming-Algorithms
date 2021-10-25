#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("max-pair.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int i=0, j=s.size()-1;
        if(s[i] != s[j]){
            cout << j - i << endl;
        }else{
            cout << j - i - 1 << endl;
        }
    }

    return 0;
}
