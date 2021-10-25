#include "bits/stdc++.h"
using namespace std;
const int maxn = 256;

int n, ans = 0;
string word;
vector<bool> visit;
vector<string> grid;

void solve(){
    if(ans == word.length()) return;
    for(int i = 0; i < n; i++){
        if(visit[i]) continue;
        for(auto e: grid[i]){
            if(e == word[ans]){
                ans++;
                visit[i] = true;
                if(ans == word.length()) return;
                solve();
                if(ans == word.length()) return;
                ans--;
                visit[i] = false;
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> word >> n;
    cin.ignore();
    grid.resize(n);
    vector<int> inicio;
    
    for(int i = 0; i < n; i++){
        getline(cin, grid[i]);
        for(auto e: grid[i])
            if(e == word[0]) inicio.push_back(i);
    }

    for(auto e: inicio){
        visit.assign(n, false);
        visit[e] = true;
        ans = 1;
        solve();
        if(ans == word.length()){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
