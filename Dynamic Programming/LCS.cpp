#include "bits/stdc++.h"
using namespace std;

const int MAXN = 3005;

int L[MAXN][MAXN];

string restore_answer(int sz, string &s, string &t){
    string ans = "";
    int i = s.size(), j = t.size();
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            ans += s[i - 1];
            i--, j--;
        }
        else if(L[i-1][j] > L[i][j-1]) i--;
        else j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

string lcs(string &s, string &t, int m, int n){
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0) L[i][j] = 0;
            else if(s[i-1] == t[j-1]) L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    return restore_answer(L[m][n], s, t);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    cout << lcs(s, t, s.size(), t.size()) << '\n';
}
