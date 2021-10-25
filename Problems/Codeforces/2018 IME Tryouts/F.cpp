#include "bits/stdc++.h"
using namespace std;

const int LIM = 3e5 + 10;
int sz[LIM], root[LIM];

int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b])
            root[b] = a;  
        else root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, ans;
    cin >> n >> m;

    for(int i = 0; i < LIM; i++){
        sz[i] = 1;
        root[i] = i;
    }

    vector<ii> ruas(m+1);
    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        ruas[i+1] = mp(u, v);
    }

    stack<int> st, resp;
    for(int i = 0; i < m; i++){
        int u; cin >> u;
        st.push(u);
    }

    //processo reverso
    ans = n;
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        resp.push(ans);
        if(find(ruas[cur].x) != find(ruas[cur].y)){
            join(ruas[cur].x, ruas[cur].y);
            ans--;
        }
    }

    while(!resp.empty()){
        cout << resp.top() << '\n';
        resp.pop();
    }

    return 0;
}
