#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    map<string, ll> mp;
    for(int i = 0; i < n; i++){
        string s, word, ans = "";
        getline(cin, s);
        stringstream ss(s);
        while(ss >> word){
            ans += word[0];
        }
        mp[ans]++;
    }
    ll resp = 0;
    for(auto e: mp){
        resp += (ll)e.second*(e.second-1)/2;
    }
    cout << resp << '\n';

    return 0;
}
