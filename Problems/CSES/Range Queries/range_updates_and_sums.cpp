#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
const int MAXN = 3e5;
const ll INF = 1e18 + 5;
 
struct Node{
    ll sum;
    ll setAll;
    ll increment;
 
    bool setAllValid;
 
    Node(){
        sum = setAllValid = increment = 0;
    }
 
    void reset(){
        setAllValid = increment = 0;
    }
};
 
int n;
int a[MAXN];
vector<Node> tree;
 
void build(int p, int l, int r){
    if(l == r) {
        if(l < n) tree[p].sum = a[l];
        else tree[p].sum = 0;
        return;
    }
    else{
        int mid = (l+r)/2;
        int lc = 2*p + 1, rc = lc + 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        tree[p].sum = tree[lc].sum + tree[rc].sum;
    }
}
 
void compose(int p, int child){
    if(tree[p].setAllValid){
        tree[child].setAllValid = 1;
        tree[child].setAll = tree[p].setAll;
        tree[child].increment = tree[p].increment;
    }
    else tree[child].increment += tree[p].increment;
}
 
void push(int p, int l, int r){
    if(tree[p].setAllValid){
        tree[p].sum = (r-l+1)*tree[p].setAll;
    }
 
    tree[p].sum += (r-l+1)*tree[p].increment;
 
    if(l != r){
        int lc = 2*p + 1, rc = lc + 1;
        compose(p, lc);
        compose(p, rc);
    }
 
    tree[p].reset();
}
 
void update_inc(int p, int l, int r, int ql, int qr, int add){
    if(r < ql || qr < l || l >= n) return;
 
    if(ql <= l && qr >= r){
        tree[p].increment += add;
        return;
    }
 
    push(p, l, r);
 
    int mid = (l + r)/2;
    int lc = 2*p + 1, rc = lc + 1;
 
    update_inc(lc, l, mid, ql, qr, add);
    update_inc(rc, mid + 1, r, ql, qr, add);
 
    push(lc, l, mid);
    push(rc, mid + 1, r);
 
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}
 
void update_set(int p, int l, int r, int ql, int qr, int x){
    if(r < ql || qr < l || l >= n) return;
 
    if(ql <= l && qr >= r){
        tree[p].setAll = x;
        tree[p].increment = 0;
        tree[p].setAllValid = 1;
        return;
    }
    push(p, l, r);
 
    int mid = (l + r)/2;
    int lc = 2*p + 1, rc = lc + 1;
 
    update_set(lc, l, mid, ql, qr, x);
    update_set(rc, mid + 1, r, ql, qr, x);
 
    push(lc, l, mid);
    push(rc, mid + 1, r);
 
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}
 
ll query(int p, int l, int r, int ql, int qr){
    if(r < ql || qr < l || l >= n) return 0;
 
    push(p, l, r);
 
    if(ql <= l && qr >= r) return tree[p].sum;
 
    int mid = (l + r)/2;
    int lc = 2*p + 1, rc = lc + 1;
 
    return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int q;
    cin >> n >> q;
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    tree.assign(4*MAXN, Node());
 
    build(0, 0, n-1);
 
    for(int i = 0; i < q; i++){
        int op, a, b, x;
        cin >> op;
        if(op == 1){
            cin >> a >> b >> x;
            update_inc(0, 0, n-1, a-1, b-1, x);
        }
        else if(op == 2){
            cin >> a >> b >> x;
            update_set(0, 0, n-1, a-1, b-1, x);
        }
        else{
            cin >> a >> b;
            cout << query(0, 0, n-1, a-1, b-1) << '\n';
        }   
    }
 
    return 0;
}
