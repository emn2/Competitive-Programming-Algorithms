#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, xa, xb, xc;

    cin >> a >> b >> c;
    cin >> xa >> xb >> xc;

    int ans = 0;
    ans = ans + max(0, xa-a) + max(0, xb-b) + max(0, xc-c);

    cout << ans << '\n';

    return 0;
}
