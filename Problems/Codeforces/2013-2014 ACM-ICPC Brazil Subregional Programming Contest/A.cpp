#include "bits/stdc++.h"
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int a, b, c;
    cin >> a >> b >> c;
 
    if(a && !b && !c) cout << "A\n";
    else if(!a && b && c) cout << "A\n";
    else if(!a && b && !c) cout << "B\n";
    else if(a && !b && c) cout << "B\n";
    else if(!a && !b && c) cout << "C\n";
    else if(a && b && !c) cout << "C\n";
    else cout << "*\n";
 
    return 0;
}
