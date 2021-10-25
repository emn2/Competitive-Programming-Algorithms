#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
const int MAXN = 1e5 + 5;

int n;
ld tree[2*MAXN];

void build(){
    for(int i = n-1; i > 0; i--){
        tree[i] = tree[2*i] + tree[2*i + 1];
    }
}

void modify(int p, ld val){
    for(tree[p += n] = val; p > 1; p /= 2){
        tree[p/2] = tree[p] + tree[p^1];
    }
}

ld query(int l, int r){
    ld ans = 0;
    for(l += n, r += n + 1; l < r; l /= 2, r /= 2){
        if(l & 1) ans += tree[l++];
        if(r & 1) ans += tree[--r];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> tree[i + n];
    
    build();

    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            ld v;
            int e;
            cin >> e >> v;
            e--;
            modify(e, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << setprecision(12) << fixed << query(l-1, r-1)/(r-l+1) << '\n';
        }
    }

    return 0;
}
