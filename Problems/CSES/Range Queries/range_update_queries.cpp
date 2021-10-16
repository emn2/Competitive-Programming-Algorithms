#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
const int LIM = 2e5 + 10;
 
int N;
vector<ll> t;
 
ll query(int p, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr) {
        if(v != -1) t[p] += v;
        return t[p];
    }
    if(r < ql || qr < l) return 0;
    int mid = (l+r)/2, lc = 2*p, rc = lc+1;
    ll sum = query(lc, l, mid, ql, qr, v) + query(rc, mid+1, r, ql, qr, v);
    return sum + t[p];
}
 
int main(){
    int q;
    cin >> N >> q;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
 
    while(__builtin_popcount(N) != 1) N++;
 
    t.resize(2*N);
 
    for(int i = 0; i < a.size(); i++)
        t[N+i] = a[i];
 
    while(q--){
        int op; cin >> op;
        if(op == 2){
            int k; cin >> k;
            k--;
            cout << query(1, 0, N-1, k, k, -1) << '\n';
        }
        else{
            int a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            query(1, 0, N-1, a, b, u);
        }
    }
 
    return 0;
}
