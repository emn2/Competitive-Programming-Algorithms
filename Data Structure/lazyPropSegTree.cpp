#include "bits/stdc++.h"
using namespace std;

//Lazy propagation
//seg tree to increment range and return minimum number in the range

int n;
int a[n+1], lo[4*n+1], hi[4*n+1], minValue[4*n+1], delta[4*n+1];

void init(int p, int l, int r){
    lo[p] = l, hi[p] = r;
    int mid = (l + r)/2, lc = 2*p, rc = lc + 1;
    if(l == r){
        minValue[p] = a[l];
        return;  //leaf
    }
    init(lc, l, mid);
    init(rc, mid+1, r);
    minValue[p] = min(minValue[lc], minValue[rc]);
}

void prop(int p){                   //se chegar em um nó com delta pendente propagar pros filhos
    int lc = 2*p, rc = lc + 1;
    delta[lc] += delta[p];
    delta[rc] += delta[p];
    delta[p] = 0;
}

void update(int p){
    int lc = 2*p, rc = lc + 1;
    //add delta because that value could not be propagated yet
    minValue[p] = min(minValue[lc] + delta[lc], minValue[rc] + delta[rc]);
}

int minimum(int p, int ql, int qr){
    //Completely disjointed, return int_max because we need the min value
    if(qr < lo[p] || ql > hi[p])
        return INT32_MAX;
    //Completely covered
    if(ql <= lo[p] && hi[p] <= qr) 
        return min[p] + delta[p];
    //Partial cover interval
    prop(p);
    int lc = 2*p, rc = lc + 1;
    int minLeft = minimum(lc, ql, qr);
    int minRight = minimum(rc, ql, qr);
    update(p);
    return min(minLeft, minRight);
}

void increment(int p, int ql, int qr, int val){
    //disjointed interval
    if(qr < lo[p] || ql > hi[p]) return;
    //Completely covered interval
    if(ql <= lo[p] && hi[p] <= qr){
        delta[p] += val;
        return;
    }
    //Partial cover interval
    prop(p);
    int lc = 2*p, rc = lc + 1;
    increment(lc, ql, qr, val);
    increment(rc, ql, qr, val);
    update(p);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    init(1, 0, n-1);

    return 0;
}
