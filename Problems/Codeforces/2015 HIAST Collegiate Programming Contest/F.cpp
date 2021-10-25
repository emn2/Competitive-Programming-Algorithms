#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, string> is;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, idx = 1;
        cin >> n;
        cin.ignore();
        vector<is> resp;
        vector<bool> vis;
        vector<string> aux;
        map<string, int> mp;
        map<int, string> corr;
        vector<vector<int> > adj(500);

        for(int i = 0; i < n; i++){
            vector<string> names;
            string s, x;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> x) names.push_back(x);

            if(mp[names[0]] == 0){
                mp[names[0]] = idx;
                corr[idx++] = names[0];
            }
            if(mp[names[1]] == 0){
                mp[names[1]] = idx;
                corr[idx++] = names[1];
            }
            if(mp[names[2]] == 0){
                mp[names[2]] = idx;
                corr[idx++] = names[2];
            }
            adj[mp[names[0]]].push_back(mp[names[1]]);
            adj[mp[names[0]]].push_back(mp[names[2]]);
            adj[mp[names[1]]].push_back(mp[names[0]]);
            adj[mp[names[1]]].push_back(mp[names[2]]);
            adj[mp[names[2]]].push_back(mp[names[0]]);
            adj[mp[names[2]]].push_back(mp[names[1]]);
            names.clear();
        }
        vis.assign(idx+5, false);
        queue<ii> q;
        q.push(make_pair(mp["Ahmad"], 0));
        vis[mp["Ahmad"]] = true;
        while(!q.empty()){
            ii cur = q.front();
            q.pop();
            resp.push_back(make_pair(cur.second, corr[cur.first]));
            for(auto e: adj[cur.first]){
                if(!vis[e]){
                    vis[e] = true;
                    q.push(make_pair(e, cur.second+1));
                }
            }
        }
        cout << idx-1 << '\n';
        sort(resp.begin(), resp.end());
        for(auto e: resp) cout << e.second << ' ' << e.first << '\n';
        for(int i = 1; i < idx; i++) 
            if(!vis[i]) aux.push_back(corr[i]);
        sort(aux.begin(), aux.end());
        for(auto e: aux) cout << e << " undefined\n";
    }

    return 0;
}
