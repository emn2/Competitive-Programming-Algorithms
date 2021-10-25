#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define lim 2000070
#define endl '\n'

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef long double ld;
typedef vector<ll> dpi;
const ll modulo = 1e9 + 7; 

class SegTree{
    public:
    ll n, q;
    vector<ll>vet, tree;
    vector<bool>treeOr, treeXor;
    SegTree(){
        cin>>n>>q;
        vet.resize(n+3);
        tree.resize((n+3)*4);
        treeOr.assign((n+3)*4, 0);
        treeXor.assign((n+3)*4, 0);
        forc(i,1,n+1){
            cin>>vet[i];
        }
        build(1,1,n);
    }
    void build(ll p, ll l, ll r){
        if(l==r){
            tree[p]= vet[l];
            if((tree[p]&1)){
                treeOr[p]=1;
            }
            if(tree[p]==1){
                treeXor[p]=1;
            }
        } else{
            ll m = (l+r)/2, lc = p*2, rc = lc+1; 
            build(lc, l, m);
            build(rc, m+1, r);
            treeOr[p]= treeOr[lc] & treeOr[rc];
            treeXor[p]= treeXor[lc] & treeXor[rc];
            tree[p]= tree[lc]+ tree[rc];
        }
    }
    void update(ll p, ll l, ll r, ll ql, ll qr, ll op){
        if(l==r){
            if(op==1){
                tree[p]= tree[p] | (tree[p]-1);
                if((tree[p]&1)){
                    treeOr[p]=1;
                }
            } else{
                tree[p]= tree[p] ^ (tree[p]-1);
                if(tree[p]==1){
                    treeXor[p]=1;
                }
            }
        } else{
            ll m = (l+r)/2, lc = p*2, rc = lc+1; 
            bool esq, dir;
            if(op==1){
                esq = treeOr[lc];
                dir = treeOr[rc];
            } else{
                esq = treeXor[lc];
                dir = treeXor[rc];
            }
            if(qr<=m){
                if(!esq){
                    update(lc, l, m, ql, qr, op);    
                }
            } else if(ql>m){
                if(!dir){
                    update(rc, m+1, r, ql, qr, op);
                }
            } else{
                if(!esq){
                    update(lc, l, m, ql, qr, op);    
                }
                if(!dir){
                    update(rc, m+1, r, ql, qr, op);
                }
            }
            treeOr[p]= treeOr[lc] & treeOr[rc];
            treeXor[p]= treeXor[lc] & treeXor[rc];
            tree[p]= tree[lc]+ tree[rc];
        }
    }
    void logica(){
        ll op,l,r;
        forc(i,0,q){
            cin>>op>>l>>r;
            update(1,1,n,l,r,op);
            cout<<tree[1]<<endl;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef ONLINE_JUDGE
    freopen("orxor.in", "r", stdin); 
    #endif
    SegTree aux;
    aux.logica();
    return 0;
}
