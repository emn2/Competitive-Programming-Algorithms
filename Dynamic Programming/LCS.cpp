#include "bits/stdc++.h"
using namespace std;

int solve(string s1, string s2, int m, int n){
    int L[m+1][n+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                L[i][j] = L[i-1][j-1] + 1; 
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[m][n];
}

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        cout << solve(s1, s2, s1.size(), s2.size()) << '\n';
    }
    return 0;
}
