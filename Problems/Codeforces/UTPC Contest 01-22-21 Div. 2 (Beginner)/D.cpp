#include "bits/stdc++.h"
using namespace std;

//ax + by + c = 0 -> eq da reta
//x = (-by - c)/a

double a, b, c, xa, ya, xb, yb;

bool solve(double xc, double yc){
    int res = -(yc*b + c)/a;
    if(xc != res) return false;
    if((xc > xa && xc > xb) || (xc < xa && xc < xb)) return false;
    return true;
}

int main(){
    int t;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> t;

    a = ya - yb;
    b = xb - xa;
    c = xa*yb - xb*ya;

    while(t--){
        double xc, yc;
        cin >> xc >> yc;
        if(solve(xc, yc)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
