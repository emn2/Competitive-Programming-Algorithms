#include "bits/stdc++.h"
using namespace std;

const int MAXN = (1 << 20);

int n;
vector<int> adj[MAXN];

void read(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int st[MAXN], en[MAXN], dep[MAXN], dfs_time;
int par[MAXN][20];

void lca_dfs(int u, int pr){
    par[u][0] = pr;
    for(int i = 1; i < 20; i++){
        par[u][i] = par[par[u][i - 1]][i - 1];
    }

    st[u] = ++dfs_time;
    for(int v: adj[u]){
        if(v != pr){
            dep[v] = dep[u] + 1;
            lca_dfs(v, u);
        }
    }

    en[u] = dfs_time;
}

bool upper(int u, int v){
    return st[u] <= st[v] && en[v] <= en[u];
}

int lca(int u, int v){
    if(upper(u, v)) return u;
    if(upper(v, u)) return v;

    for(int i = 19; i >= 0; i--){
        if(!upper(par[u][i], v)){
            u = par[u][i];
        }
    }

    return par[u][0];
}

void precompute_lca(int root){
    dep[root] = 0;
    lca_dfs(root, root);
}

// Virtual Tree

vector<int> adj_vt[MAXN];

bool cmp(int u, int v) {
    return st[u] < st[v];
}

int virtual_tree(vector<int> vert){
    sort(vert.begin(), vert.end(), cmp);

    int k = vert.size();
    for(int i = 0; i < k - 1; i++){
        int new_vertex = lca(vert[i], vert[i + 1]);
        vert.push_back(new_vertex);
    }

    sort(vert.begin(), vert.end(), cmp);
    vert.erase(unique(vert.begin(), vert.end()), vert.end());

    for(int v: vert)
        adj_vt[v].clear();

    vector<int> stack_of_vertices;
    stack_of_vertices.push_back(vert[0]);

    for(int i = 1; i < vert.size(); i++){
        int u = vert[i];
        while(stack_of_vertices.size() >= 2 && !upper(stack_of_vertices.back(), u)){
            //ADD EDGE
            adj_vt[stack_of_vertices[stack_of_vertices.size() - 2]].push_back(stack_of_vertices.back());
            stack_of_vertices.pop_back();
        }

        stack_of_vertices.push_back(u);
    }

    while(stack_of_vertices.size() >= 2){
        adj_vt[stack_of_vertices[stack_of_vertices.size() - 2]].push_back(stack_of_vertices.back());
        stack_of_vertices.pop_back();
    }

    return stack_of_vertices[0];
}

bool important[MAXN];
int subtree_count[MAXN];
int TOTAL_COUNT = 0;

long long solve(int u, int pr = -1){
    long long ans = 0;
    subtree_count[u] = important[u];
    for(int v: adj_vt[u]){
        ans += solve(v, u);
        subtree_count[u] += subtree_count[v];
    }

    if(pr != -1){
        int w = dep[u] - dep[pr];
        ans += w * 1LL * subtree_count[u] * 1LL * (TOTAL_COUNT - subtree_count[u]);
    }

    return ans;
}

void solve(){
    //1-based
    precompute_lca(1);

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> ver;
        while(k--){
            int x;
            cin >> x;
            important[x] = true;
            ver.push_back(x);
        }

        TOTAL_COUNT = ver.size();

        int vt_root = virtual_tree(ver);
        cout << solve(vt_root) << "\n";

        for(int x: ver)
            important[x] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    return 0;
}
