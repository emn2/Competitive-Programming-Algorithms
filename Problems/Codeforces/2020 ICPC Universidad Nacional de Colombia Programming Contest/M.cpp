#include "bits/stdc++.h"
using namespace std;
const int alpha = 26;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    string word;
    getline(cin, word);
    int n; 
    cin >> n;
    cin.ignore();
    
    vector<vector<int> > index(alpha);
    for(int i = 0; i < word.size(); i++) index[word[i]-'a'].push_back(i);
 
    for(int i = 0; i < n; i++){
        string s, ans = "";
        getline(cin, s);
        if(index[s[0]-'a'].size() == 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        ans += s[0];
        int idx = *index[s[0]-'a'].begin();
 
        for(int j = 1; j < s.size(); j++){
            if(index[s[j]-'a'].size() > 0){
                auto new_ = upper_bound(index[s[j]-'a'].begin(), index[s[j]-'a'].end(), idx);
                if(idx > *new_ || new_ == index[s[j]-'a'].end()) break;
                else{
                    ans += s[j];
                    idx = *new_;
                }
            }
            else break;
        }
        cout << ans << '\n';
    }   
 
    return 0;
}
