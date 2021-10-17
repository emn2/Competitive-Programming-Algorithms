#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;

typedef pair<pair<int, int>, int> ii;

int sz = INF;
vector<bool> vis;   
vector<int> par, resp;
vector<vector<int> > adj;

void build(int origin){
    int aux = origin;
    resp.clear();
    for(int i = 0; i < sz; i++){
        resp.push_back(aux);
        aux = par[aux];
    }
}

void bfs(int origin){
    vis[origin] = true;
    par[origin] = origin;

    queue<ii> q;
    q.push(make_pair(make_pair(origin, origin), 1));
    while(!q.empty()){
        int u = q.front().first.first;
        int pai = q.front().first.second;
        int d = q.front().second;

        q.pop();

        for(auto v: adj[u]){
            if(v == origin){
                if(sz > d){
                    sz = d;
                    build(u);
                }
            }
            else if(!vis[v]){
                par[v] = u;
                vis[v] = true;
                q.push(make_pair(make_pair(v, u), d + 1));
            }
        }
    }
}

void dfs(int u, int p, int origin, int tam){
    if(vis[u]){
        if(origin == u){
            if(tam < sz){
                sz = tam;
                par[u] = p;
                build(origin);
            }
        }
        return;
    }
    vis[u] = true;
    par[u] = p;
    for(auto v: adj[u]){
        dfs(v, u, origin, tam + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> mp;
    map<int, string> mp_rev;

    adj.resize(n);
    par.resize(n);
    vis.assign(n, false);

    for(int i = 0; i < n; i++){
        string file;
        cin >> file;
        mp[file] = i;
        mp_rev[i] = file;
    }

    for(int i = 0; i < n; i++){
        int qntd;
        string origin;

        cin >> origin >> qntd;

        cin.ignore();

        for(int j = 0; j < qntd; j++){
            string s;
            getline(cin, s);

            string to;
            int idx = 7;
            for(int k = 7; k < s.length(); k++){
                if(s[k] == ' '){
                    to = s.substr(idx, k - idx - 1);
                    adj[mp[origin]].push_back(mp[to]);
                    idx = k + 1;
                }
                else if(k == s.length() - 1){
                    to = s.substr(idx, k - idx + 1);
                    adj[mp[origin]].push_back(mp[to]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        //dfs(i, i, i, 0);
        bfs(i);
        vis.assign(n, false);
    }

    if(sz == INF) cout << "SHIP IT\n";
    else{
        reverse(resp.begin(), resp.end());
        for(auto e: resp){
            cout << mp_rev[e] << ' ';
        }
    }

    return 0;
}
