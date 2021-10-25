#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;

int n, m;
vector<vector<int> > adj;
vector<vector<int> > capacity;

int sum(string &s){
    int soma = 0;
    soma = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    return soma;
}

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q;
    q.push(make_pair(s, INF));

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push(make_pair(next, new_flow));
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+m+5);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    map<int, pair<string, string> > mp;

    capacity.assign(n+m+5, vector<int>(n+m+5, 0));
    adj.resize(n+m+5);

    int cnt = 1;
    int src = 0, snk = n+m+1;

    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        mp[cnt++] = make_pair(a.substr(0, 3), a.substr(3));
    }
    for(int i = 0; i < m; i++){
        string a;
        cin >> a;
        mp[cnt++] = make_pair(a.substr(0, 3), a.substr(3));
    }

    for(int i = 1; i <= n; i++) {
        adj[src].push_back(i);
        adj[i].push_back(src);
        capacity[src][i] = 1;
    }
    for(int j = n+1; j <= m+n; j++) {
        adj[j].push_back(snk);
        adj[snk].push_back(j);
        capacity[j][snk] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = n+1; j <= m+n; j++){
            if(sum(mp[i].first) == sum(mp[j].second) || sum(mp[i].second) == sum(mp[j].first)){
                adj[i].push_back(j);
                adj[j].push_back(i);
                capacity[i][j] = 1;
            }
        }
    }

    cout << maxflow(src, snk) << '\n';

    for(int i = 1; i <= n; i++){
        if(capacity[src][i] == 0){
            for(auto e: adj[i]){
                if(capacity[i][e] == 0){
                    if(sum(mp[i].first) == sum(mp[e].second)){
                        cout << "AT " << mp[i].first << mp[i].second << ' ' << mp[e].first << mp[e].second << '\n';
                    }
                    else{
                        cout << "TA " << mp[e].first << mp[e].second << ' ' << mp[i].first << mp[i].second << '\n';
                    }
                }
            }
        }
    }
    
    return 0;
}
