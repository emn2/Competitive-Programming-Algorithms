#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = 0, total = 0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a >= 0) total += a;
        else{
            a *= -1;
            if(total < a){
                ans += (a - total);
                total = 0;
            }
            else total -= a;
        }
    }

    cout << ans;

    return 0;
}
