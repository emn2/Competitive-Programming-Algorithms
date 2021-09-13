typedef struct item* pitem;

mt19937 rng ((int) chrono::steady_clock::now().time_since_epoch().count());

struct item {
    item() {}
    item (int v) { // add key if not implicit
        key = v;
        prior = uniform_int_distribution<int>() (rng);
        subtreeSize = 1;
        toReverse = 0;
        toProp = sum = 0;
        l = r = 0;
    }
    pitem l, r;
    int key, toProp, sum;
    int prior, subtreeSize;
    bool toReverse;
};

int cnt(pitem t){
    return (t ? t->subtreeSize : 0);
}

void update_cnt(pitem t){
    if(t){
        t->subtreeSize = 1 + cnt(t->l) + cnt(t->r);
    }
}

void split(pitem t, int key, pitem &l, pitem &r){
    if(!t) l = r = NULL;
    else if(t->key <= key){
        split(t->r, key, t->r, r);
        l = t;
    }
    else{
        split(t->l, key, l, t->l);
        r = t;
    }
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (t->key <= it->key ? t->r : t->l, it);
}

void merge(pitem &t, pitem l, pitem r){
    if(!l || !r){
        t = (l ? l : r);
    }
    else if(l->prior > r->prior){
        merge(l->r, l->r, r);
        t = l;
    }
    else{
        merge(r->l, l, r->l);
        t = r;
    }
}

void erase(pitem &t, int key){
    if(t->key == key){
        pitem th = t;
        merge(t, t->l, t->r);
        delete th;
    }
    else{
        erase((key < t->key ? t->l : t->r), key);
    }
}

pitem unite(pitem l, pitem r){
    if(!l || !r) return (l ? l : r);
    if(l->prior < r->prior) swap(l, r);
    pitem lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}

void push (pitem it) {
    if (it && it->toReverse) {
        it->toReverse = false;
        swap (it->l, it->r);
        if (it->l)  it->l->toReverse ^= true;
        if (it->r)  it->r->toReverse ^= true;
    }
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, l, t1, t2);
    split (t2, r-l+1, t2, t3);
    t2->toReverse ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    printf ("%d ", t->key);
    output (t->r);
}
