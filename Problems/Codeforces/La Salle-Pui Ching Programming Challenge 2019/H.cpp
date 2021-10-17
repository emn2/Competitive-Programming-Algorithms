#include "bits/stdc++.h"
using namespace std;

int solve(int d1, int d2, int d3, int sa, int sb, int sc){
    int ans = 0;

    if(sa > d1) ans++;
    if(sb > d2) ans++;
    if(sc > d3) ans++;

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d1, d2, d3;
    int sa, sb, sc;

    cin >> d1 >> d2 >> d3;
    cin >> sa >> sb >> sc;

    int ans = 0;

    //1 2 3
    ans = max(ans, solve(d1, d2, d3, sa, sb, sc));
    //1 3 2
    ans = max(ans, solve(d1, d2, d3, sa, sc, sb));
    //2 1 3
    ans = max(ans, solve(d1, d2, d3, sb, sa, sc));
    //2 3 1
    ans = max(ans, solve(d1, d2, d3, sb, sc, sa));
    //3 1 2
    ans = max(ans, solve(d1, d2, d3, sc, sa, sb));
    //3 2 1
    ans = max(ans, solve(d1, d2, d3, sc, sb, sa));

    cout << ans << '\n';

    return 0;
}
