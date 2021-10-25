#include "bits/stdc++.h"
using namespace std;

bool vogal(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);
    vector<string> silabas = {"shi", "chi", "dzu", "tsu", "te", "to", "ka", "ki", "ku", "ke",
        "ko", "ga", "gi", "gu", "ge", "go", "sa", "su", "se", "so", "za", "ji", "zu", "ze", "zo",
        "ta", "da", "di", "de", "do", "ne", "ni", "nu", "na", "no", "ha", "hi", "fu", "he", "ho",
        "ba", "bi", "bu", "be", "bo", "pa", "pi", "pu", "pe", "po", "ma", "mi", "mu", "me", "mo",
        "ya", "yu", "yo", "ra", "ri", "ru", "re", "ro", "wa", "wo", "we", "wi", "n", "a", "e", "i",
        "o", "u", "kya", "kyu", "kyo", "gya", "gyu", "gyo", "sha", "shu", "sho", "cha", "chu", "cho",
        "dya", "dyu", "dyo", "nya", "nyu", "nyo", "hya", "hyu", "hyo", "bya", "byu", "byo", "pya",
        "pyu", "pyo", "mya", "myu", "myo", "rya", "ryu", "ryo", "ja", "ju", "jo"};

    string resp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == '!' || 
           s[i] == '?' || s[i] == '-' || s[i] == ')' || s[i] == '('){
            resp += s[i];
            resp += ' ';
            continue;
        }
        if(i+1 < s.length() && s[i] == s[i+1] && !vogal(s[i])){
            resp += s[i];
            resp += ' ';
            continue;
        }
        for(int j = 0; j < silabas.size(); j++){
            int n = silabas[j].length();
            if(i + n <= s.size()){
                string s1;
                s1 = s.substr(i, n);
                if(s1 == silabas[j]){
                    resp += s1;
                    resp += ' ';
                    i += n - 1;
                    break;
                }
            }
        }
    }

    cout << resp << '\n';

    return 0;
}
