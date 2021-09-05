//Lazy propagation
//seg tree to increment range and return maximum number in the range

const int MAXN = 1e6;
const int INF = 1e9 + 5;
int a[MAXN], tree[4*MAXN], lazy[4*MAXN];

void build(int p, int l, int r){
    if(l == r){
        tree[p] = a[l];
    }
    else{
        int mid = (l + r)/2;
        int lc = 2*p, rc = lc + 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        tree[p] = tree[rc] + tree[lc];
    }
}

void push(int p){
    int lc = 2*p, rc = lc + 1;
    
    tree[lc] += lazy[p];
    lazy[lc] += lazy[p];

    tree[rc] += lazy[p];
    lazy[rc] += lazy[p];

    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int add){
    if(ql > qr) return;

    if(l == ql && r == qr){
        tree[p] += add;
        lazy[p] += add;
    }
    else{
        push(p);
        int mid = (l + r)/2;
        int lc = 2*p, rc = lc + 1;
        update(lc, l, mid, ql, min(qr, mid), add);
        update(rc, mid + 1, r, max(ql, mid + 1), qr, add);
        tree[p] = max(tree[lc], tree[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql > qr) return -INF;

    if(ql <= l && r <= qr) return tree[p];

    push(p);
    int mid = (l + r)/2;
    int lc = 2*p, rc = lc + 1;

    int query_left = query(lc, l, mid, ql, min(qr, mid));
    int query_right = query(rc, mid + 1, r, max(l, mid + 1), qr);

    return max(query_left, query_right);
}
