#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
const int LIM = 2e5;
ll N, t[LIM << 1];
 
void build(){
    for (int i = N - 1; i; i--)
        t[i] = t[i << 1] + t[i << 1 | 1];
}
 
ll query(int l, int r){
    ll res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1){
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}
 
void update(int i, int val){
    i += N;
    for(t[i] = val; i > 1; i >>= 1)
        t[i>>1] = t[i] + t[i^1];
}
 
int main(){
    int q;
    cin >> N >> q;
    for (int i = 0; i < N; i++) cin >> t[i + N];
    build();
 
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        a--;
        if(op == 1) update(a, b);
        else cout << query(a, b) << '\n';
    }
 
    return 0;
}
