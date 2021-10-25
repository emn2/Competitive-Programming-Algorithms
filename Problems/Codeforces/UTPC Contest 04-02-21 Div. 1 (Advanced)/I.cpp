#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2005;

typedef long long ll;

struct FlowEdge {
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int> > adj;

    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int id : adj[v]) {
                if(edges[id].cap - edges[id].flow < 1)
                    continue;
                if(level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int color[MAXN];
vector<int> adjL[MAXN];

bool bfsColor(int x){
    color[x] = 0;
    queue<int> q;

    q.push(x);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adjL[u]){
            if(color[v] == -1){
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}

bool isPrime(int x){
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> id;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        id[a[i]] = i+1;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(isPrime(a[i] + a[j])){
                adjL[id[a[i]]].push_back(id[a[j]]);
                adjL[id[a[j]]].push_back(id[a[i]]);
            }
        }
    }
    
    int src = 0, snk = n+1;
    memset(color, -1, sizeof(color));

    Dinic dinic(n + 2, src, snk);

    for(int i = 1; i <= n; i++){
        if(color[i] == -1) bfsColor(i);

        if(!color[i]){
            dinic.add_edge(src, i, 1);
            for(int j: adjL[i]){
                dinic.add_edge(i, j, 1);
            }
        }
        else{
            dinic.add_edge(i, snk, 1);
        }
    }

    cout << n - dinic.flow() << '\n';

    return 0;
}
