#include "bits/stdc++.h"
using namespace std;

int solve(string creator_name, string gang_name, vector<string>& grid){
    int ans = 0, qntd = 1e8;
    map<char, int> nec_creator;
    map<char, int> nec_gang;
    map<char, int> mp;

    for(auto e: creator_name) nec_creator[e]++;
    for(auto e: gang_name) nec_gang[e]++;

    for(auto s: grid){
        for(auto e: s) mp[e]++;
    }
    for(auto e: nec_creator) qntd = min(qntd, mp[e.first]/e.second);
    ans += qntd;
    for(auto e: nec_creator) mp[e.first] -= qntd*e.second;

    for(auto e: nec_gang) qntd = min(qntd, mp[e.first]/e.second);
    ans += qntd;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, ans = -1, index = 0;
    cin >> t;
  
    //string creator_name, gang_name;
    vector<pair<string, string> > p(t);
    for(int i = 0; i < t; i++){
        cin >> p[i].first >> p[i].second;
    }   
    for(int i = 0; i < t; i++){
        int n, m, aux;
        cin >> n >> m;
        cin.ignore();
        vector<string> grid(n);
        for(int i = 0; i < n; i++) getline(cin, grid[i]);
        aux = solve(p[i].first, p[i].second, grid);
        if(aux > ans){
            index = i;
            ans = aux;
        }
    }

    cout << p[index].first << ' ' << p[index].second;

    return 0;
}
