#include "bits/stdc++.h"
using namespace std;

bool check(double l, double r, double k){
    if(abs(l-r) < k && k < l+r) return true;
    return false;
}

double get_area(double a, double b, double c, double k){
    double max_area = 0;
    double p = (a+b+c+k)/2.0;
    
    if(check(a+k,b,c) && check(c,a+k,b) && check(c,b,a+k))
        max_area = max(max_area, sqrt(p*(p-(a+k))*(p-b)*(p-c)));

    return max_area;
}

double solve(double a, double b, double c, double k){
    double k_maximo = sqrt(b*b + c*c) - a;

    return get_area(a, b, c, min(k, k_maximo));
}   

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    #ifdef ONLINE_JUDGE
    freopen("sticks.in", "r", stdin); 
    #endif

    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int a, b, c, k;
        double area = 0;
        cin >> a >> b >> c >> k;

        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);

        cout << solve(a, b, c, k) << '\n';
    }
    return 0;
}
