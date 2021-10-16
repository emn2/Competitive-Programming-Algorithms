#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
int main(){
    int n; 
    cin >> n;
 
    ll ans = 0;
    int last = 0;
    for(int i = 0; i < n; i++){
        int a, obj; 
        cin >> a;
        obj = last;
        if(a < last) {
            ans += obj-a;
            last = obj;
        }
        else last = a;
    }
    cout << ans << '\n';
    return 0;
}
