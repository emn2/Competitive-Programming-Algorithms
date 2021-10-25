#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x >= 8128)
            cout << 8128 << '\n';
        else if(x >= 496)
            cout << 496 << '\n';
        else if(x >= 28)
            cout << 28 << '\n';
        else if(x >= 6)
            cout << 6 << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
