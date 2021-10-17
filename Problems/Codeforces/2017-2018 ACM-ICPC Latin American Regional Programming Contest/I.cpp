#include "bits/stdc++.h"
using namespace std;

struct HLD {
    std::vector<int> tin, tout, sz, rin, p, nxt, h;
    std::vector<std::vector<int>> adj;
    int t;
    HLD(int n):tin(n),tout(n),sz(n),rin(n),p(n),nxt(n),h(n),adj(n){}
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    void setRoot(int n) {
        t = 0;
        p[n] = n;
        h[n] = 0;
        prep(n, n);
        nxt[n] = n;
        hld(n,n);
    }
 
    int getLCA(int u, int v) {
        while(!inSubtree(nxt[u], v)) u = p[nxt[u]];
        while(!inSubtree(nxt[v], u)) v = p[nxt[v]];
        return tin[u] < tin[v] ? u : v;
    }
 
    bool inSubtree(int u, int v) {
        // is v tin the subtree of u
        return tin[u] <= tin[v] && tin[v] < tout[u];
    }
 
    std::vector<std::pair<int, int>> getPathtoAncestor(int u, int anc) {
        // returns ranges [l, r) that the path has
        std::vector<std::pair<int, int>> ans;
    
        while(nxt[u] != nxt[anc]) {
            ans.emplace_back(tin[nxt[u]], tin[u] + 1);
            u = p[nxt[u]];
        }
        // this includes the ancestor!
        ans.emplace_back(tin[anc] + 1, tin[u] + 1);
        return ans;
    }
    void prep(int u, int par) {
        sz[u] = 1;
        p[u] = par;
        for(int& v : adj[u]) {
            if(v != par){
                h[v] = 1 + h[u];
                prep(v, u);
                sz[u] += sz[v];
                if(sz[v] > sz[adj[u][0]] || adj[u][0] == v) {
                    std::swap(adj[u][0], v);
                }
            }
        }
    }
 
    void hld(int u, int par) {
        tin[u] = t++;
        rin[tin[u]] = u;
        for(auto v : adj[u]) {
            if(v == par)continue;
            nxt[v] = (v == adj[u][0] ? nxt[u] : v);
            hld(v,u);
        }
        tout[u] = t;
    }
};
struct DSU{
    vector<int>p,sz;
    DSU(int n):p(n),sz(n){//0-based
        iota(p.begin(),p.end(),0);
        fill(sz.begin(),sz.end(),1);
    }
    int root(int a){
        return p[a]=(p[a]==a?a:root(p[a]));//path compression
    }
    bool unite(int a, int b){
        a=root(a);
        b=root(b);
 
        if(a!=b){
            //Union by size
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            p[b]=a;
            sz[a]+=sz[b];
            return true;
        }else{
            return false;
        }
    }
    int size(int x){
        return sz[root(x)];
    }
    int count(){
        int n = (int)p.size(),cnt=0;
        for(int i=0;i<n;i++){
            cnt+=i==root(i) ? 1 : 0;
        }
        return cnt;
    }
};
 
struct Edge{
    int u,v,w;
    Edge(int u,int v, int w):u(u),v(v),w(w){}
    bool operator<(const Edge& a){ // operator for sort function
        return w < a.w;
    }
};
 
struct node{
    int x;
    node(int _x=0):x(_x){}
    node operator+(const node &o){ // merge function
        return node(max(x,o.x));
    }
}nil(0);

struct SegmentTree{
    int n;
    vector<node>tree;
    SegmentTree(int _n=0):n(_n),tree(4*n,nil){}
    void update(int pos,int tl,int tr,int x, node val){
        int esq=2*pos, dir=2*pos+1;
        int mid = (tl+tr)/2;
        if(tl==tr){
            tree[pos]=tree[pos]+val;//assign update
        }else{
            if(x<=mid)update(esq,tl,mid,x,val);
            else update(dir,mid+1,tr,x,val);
     
            tree[pos]=tree[esq]+tree[dir];
        }
    }
 
    void update(int x, int val){
        update(1,0,n-1,x,node(val));
    }
 
    node query(int pos, int tl, int tr, int l, int r){
        int esq=2*pos, dir=2*pos+1;
        int mid = (tl+tr)/2;
     
        if(tl>r || tr<l){
            return nil;//depends of the query type
        }else if(tl>=l && tr<=r){
            return tree[pos];
        }else{
            return query(esq,tl,mid,l,r)+query(dir,mid+1,tr,l,r);
        }
    }
    int query(int l, int r){
        return query(1,0,n-1,l,r).x;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r;
    cin>>n>>r;
    map<pair<int,int>,int>cost;
    vector<Edge>e;
    for(int i=0;i<r;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u;--v;
        e.push_back(Edge(u,v,w));
        cost[{u,v}] = w;
    }
    sort(begin(e),end(e));
    DSU ds(n);
    HLD h(n);
    long long ans = 0;
    map<tuple<int,int>,int>onMst;
    for(auto [u,v,w] : e){
        if(ds.unite(u,v)){
            ans += w;
            onMst[{u,v}] = w;
            h.addEdge(u,v);
        }
    }
    h.setRoot(0);
    SegmentTree t(n);
    for(auto [p,w] : onMst){
        auto [u,v] = p;
        tie(u,v) = minmax(h.tin[u],h.tin[v]);
        t.update(v,w);
    }
    int q;cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        --a;--b;
        if(onMst.count({a,b})){
            cout<<ans<<'\n';
        }else{
            int c = h.getLCA(a,b);
            int w = cost[{a,b}];
            int mx = 0;
            for(int e=0;e<2;++e){
                auto v = h.getPathtoAncestor(a,c);
                for(auto [l,r] : v){
                    mx = max(mx, t.query(l,r-1));
                }
                swap(a,b);
            }
            cout<<ans - mx + w<<'\n';
        }
    }
    return 0;
}
