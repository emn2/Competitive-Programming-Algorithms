#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
typedef long long ll;
 
vector<int> a;
vector<vector<int> > adj;
 
class HLD{
    vector<int> sz;
    vector<int> pos;
    vector<int> head;
    vector<int> level;
    vector<int> parent;
 
    vector<int> tree;
 
    int N;
 
    int query(int p, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return 0;
        else if(ql <= l && r <= qr) return tree[p];
 
        int mid = (l + r) >> 1;
        int lc = 2*p, rc = lc + 1;
 
        return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
    }
 
    void update(int p, int l, int r, int pos, int w){
        if(l == r){
            tree[p] = w;
            return;
        }
 
        int mid = (l + r) >> 1;
        int lc = 2*p, rc = lc + 1;
 
        if(pos <= mid) update(lc, l, mid, pos, w);
        else update(rc, mid + 1, r, pos, w);
 
        tree[p] = tree[lc] + tree[rc];
    }
 
    void dfs(int u, int lvl){
        sz[u] = 1;
        level[u] = lvl;
        int bigChild = 0;
 
        for(auto &cur: adj[u]){
            int v = cur;
            if(v == parent[u]) continue;
            parent[v] = u;
 
            dfs(v, lvl + 1);
 
            sz[u] += sz[v];
 
            if(sz[v] > bigChild){
                swap(cur, adj[u][0]);
            }
            bigChild = max(bigChild, sz[v]);
        }
    }
 
    void decompose(int u, int &x, bool keep){
        if(keep) head[u] = head[parent[u]];
        else head[u] = u;
 
        pos[u] = x++;
 
        if(sz[u] > 1) decompose(adj[u][0], x, true);
 
        for(int i = 1; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(v == parent[u]) continue;
            decompose(v, x, 0);
        }
    }
 
    public:
        HLD(int n){
            N = n;
            sz.assign(n+5, -1);
            pos.assign(n+5, -1);
            head.assign(n+5, -1);
            level.assign(n+5, -1);
            parent.assign(n+5, -1);
            tree.assign(4*n + 5, 0);
        }
 
        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        void init(){
            parent[0] = -1;
            dfs(0, 0);
            int x = 0;
            decompose(0, x, 0);
        }
 
        void get(int u, int v){
            int l = 0, res = 0;
 
            while(head[v] != head[l]){
                res += query(1, 0, N-1, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
 
            res += query(1, 0, N-1, pos[0], pos[v]);
 
            cout << res << '\n';
        }
 
        void hld_update(int u, int w){
            update(1, 0, N-1, pos[u], w);
        }
};
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n, q;
    cin >> n >> q;
 
    HLD hld(n);
    a.resize(n+5);
    adj.resize(n+5);
 
    for(int i = 0; i < n; i++) cin >> a[i];
 
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }
 
    hld.init();
 
    for(int i = 0; i < n; i++){
        hld.hld_update(i, a[i]);
    }
 
    while(q--){
        int op, s, x;
        cin >> op;
        if(op == 1){
            cin >> s >> x;
            s--;
            hld.hld_update(s, x);
        }
        else{
            cin >> s;
            s--;
            hld.get(0, s);
        }
    }
 
    
    return 0;
}
