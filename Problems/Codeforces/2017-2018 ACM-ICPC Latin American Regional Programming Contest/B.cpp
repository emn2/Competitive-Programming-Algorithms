#include "bits/stdc++.h"
using namespace std;

string s;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int solve(int l, int r, int vowels){
    if(l == r) return 1;

    int dir = (l < r) ? 1 : -1;

    if(!isVowel(s[l])) return vowels ? 0 : 1;
    if(isVowel(s[r])) return solve(r, l + dir, vowels - 1);

    return solve(l, r-dir, vowels) + solve(r, l+dir, vowels-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int len = s.length();
    int cntConsoant = 0, cntVowel = 0;

    for(auto e: s){
        if(isVowel(e)) cntVowel++;
        else cntConsoant++;    
    }

    if(cntVowel == len || cntConsoant == len) cout << "1\n";
    else if(!isVowel(s[0])) cout << "0\n";
    else{
        cout << solve(0, len-1, cntVowel);
    }

    return 0;
}
