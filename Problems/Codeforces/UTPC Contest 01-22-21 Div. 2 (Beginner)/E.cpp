#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    string s;
    ll n, ans = 1;
    getline(cin, s);

    if(s.size() == 1) n = s[0] - '0';
    else{
        n = s.size() - 2;
        n = stoi(s.substr(n));
    }

    //Para o mod 2
    if(n%4 == 0) ans += 1;
    else if(n%4 == 1) ans += 2;
    else if(n%4 == 2) ans += 4;
    else ans += 3;

    //Para o mod 3
    if(n%4 == 0) ans += 1;
    else if(n%4 == 1) ans += 3;
    else if(n%4 == 2) ans += 4;
    else ans += 2;

    //Para o mod 4
    if(n%2 == 0) ans += 1;
    else ans += 4;

    cout << ans%5 << '\n';

    return 0;
}
