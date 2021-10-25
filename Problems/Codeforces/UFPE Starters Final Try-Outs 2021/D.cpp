#include "bits/stdc++.h"
using namespace std;

int pergunta(int x, int y){
    cout << x << ' '  << y << '\n';
    int z; cin >> z;
    return z;
}

int main(){
    int n, ok;
    cin >> n;

    int l = 1, mid = (1+n)/2, r = n;

    while(1){
        int ok;
        ok = pergunta(l, mid);
        if(l == r && ok){
            cout << "! " << l << '\n';
            break;
        } 
        if(ok){
            r = mid;
            mid = (l+r)/2;
        }
        else{
            l = mid+1;
            mid = (l+r)/2;
        }
    }

    return 0;
}
