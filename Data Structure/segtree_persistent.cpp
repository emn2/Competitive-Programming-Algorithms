struct Node{
    int val = 0;
    Node *l = this, *r = this;
};

const int MAXN = 1e5;

Node buffer[20*MAXN];
Node *root[MAXN + 1];

int cnt = 0;

Node *update(Node *on, int ql, int qr, int i, int v){
    Node *node = &buffer[cnt++];
    *node = *on;

    if(ql + 1 == qr){
        node->val = v;
        return node;
    }
    else{
        int mid = (ql + qr) >> 1;
        if(i < mid) node->l = update(on->l, ql, mid, i, v);
        else node->r = update(on->r, mid, qr, i, v);

        node->val = node->l->val + node->r->val;

        return node;
    }
}

int query(Node *on, int ql, int qr, int l, int r){
    if(ql >= r || qr <= l) return 0;
    else if(l <= ql && qr <= r) return on->val;
    else{
        int mid = (ql + qr) >> 1;
        return query(on->l, ql, mid, l, r) + query(on->r, mid, qr, l, r);
    }
}
