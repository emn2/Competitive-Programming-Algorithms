#include "bits/stdc++.h"
using namespace std;

int sum(string &s){
    int n = s.length() - 1;
    int ans = 9*n + (s[0] - '1');

    for(int i = 1; i <= n; i++){
        if(s[i] != '9') return ans;
    }
    return ans + 1;
}

int solve(string &s){
    int n = s.length() - 1;
    
    if(n == 0) return (s[0] - '0');
    else return sum(s);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("lis.in", "r", stdin);

    string s;
    cin >> s;

    cout << solve(s) << '\n';

    return 0;
}
