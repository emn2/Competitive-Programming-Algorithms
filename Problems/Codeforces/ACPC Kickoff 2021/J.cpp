#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("two2.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2 == 0){
            cout << n/2 << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
