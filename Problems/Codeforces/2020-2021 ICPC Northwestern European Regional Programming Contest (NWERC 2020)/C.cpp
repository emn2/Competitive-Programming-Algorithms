#include "bits/stdc++.h"
using namespace std;
typedef long double ld;

int main(){
    ld n, k, d, s;
    cin >> n >> k >> d >> s;

    ld total = d*n;
    ld solved = k*s;
    ld mean = (total - solved)/(n-k);

    if(mean > 100 || mean < 0) printf("impossible");
    else printf("%Lf", mean);

    return 0;
}
