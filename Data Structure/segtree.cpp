#include "bits/stdc++.h"
using namespace std;
#define int long long

const int N = 1e5 + 5;
int tree[4*N], a[N];

void build(int p, int l, int r){ 
    if(l == r) {
        tree[p] = a[l];
    } else {
        int m = (l + r) / 2, lc = 2*p, rc = lc + 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        tree[p] = min(tree[lc], tree[rc]);
    }
}

void update(int p, int l, int r, int i, int x){ //i -> posicao a ser atualizada, x -> novo valor
    if(l == r){
        tree[p] = a[i] = x;
    } else {
        int m = (l + r) / 2, lc = 2*p, rc = lc + 1;
        if(i <= m){
            update(lc, l, m, i, x)
        } else {
            update(rc, m + 1, r, i, x);
        }
        tree[p] = min(tree[lc], tree[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return tree[p];
    } else {
        int m = (l + r) / 2, lc = 2*p, rc = lc + 1;
        if(qr <= m){
            return query(lc, l, m, ql, qr);
        } else if (ql > m){
            return query(rc, m + 1, r, ql, qr);
        } else {
            return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
        }
    }
}

int32_t main(){
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> a[i];
    }
    build(1, 1, q);
    return 0;
}
