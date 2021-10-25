#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int max_ = 1e9;
    
    for(int i = 0; i < n; i++){
        int need, have;
        cin >> need >> have;
        max_ = min(max_, have/need);
    }
    cout << max_;
    return 0;
}
