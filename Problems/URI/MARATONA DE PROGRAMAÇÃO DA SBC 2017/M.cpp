#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << min(2*b + 4*c, min(2*a + 2*c, 4*a + 2*b)) << '\n';
}
