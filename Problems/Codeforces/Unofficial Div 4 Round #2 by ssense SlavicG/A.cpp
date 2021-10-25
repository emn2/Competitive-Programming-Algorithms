#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    if(s.size() == n-1)
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}
