#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

template<class T>
T binExp(T a, long long e){
    T r(1);
    for(;e;e>>=1){
        if(e&1)r = r * a;
        a = a * a;
    }
    return r;
}
struct MB{
    int x;
    MB(int _x=0):x(_x){}
    void operator +=(const MB& o){ *this = *this + o; }
    void operator -=(const MB& o){ *this = *this - o; }
    void operator *=(const MB& o){ *this = *this * o; }
    void operator /=(const MB& o){ *this = *this / o; }
    MB& operator ++(){ return *this = *this + MB(1); }
    MB operator ++(int){ MB r=*this; ++(*this); return r; }
    MB operator +(const MB& o){ return x+o.x >=mod ? x+o.x-mod : x+o.x; }
    MB operator -(const MB& o){ return x-o.x < 0 ? x-o.x+mod : x-o.x; }
    MB operator *(const MB& o){ return int(1ll*x*o.x%mod); }
    MB operator /(const MB& o){ return *this * binExp(o,mod-2); }
    operator int(){return x;}
    friend ostream& operator<< (ostream& os, MB& o) { return os << o.x; }
    friend istream& operator>> (istream& is, MB& o) { return is >> o.x; }
};

struct DSU{
    vector<int>p,sz;
    DSU(int n):p(n),sz(n){//0-based
        iota(p.begin(),p.end(),0);
        fill(sz.begin(),sz.end(),1);
    }
    int root(int a){
        return p[a]=(p[a]==a?a:root(p[a]));//path compression
    }
    void unite(int a, int b){
        a=root(a);
        b=root(b);
 
        if(a!=b){
            //Union by size
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            p[b]=a;
            sz[a]+=sz[b];
        }
    }
    int size(int x){
        return sz[root(x)];
    }
    int count(){
    	int n = (int)p.size(),cnt=0;
    	for(int i=0;i<n;i++){
    		cnt+=i==root(i) ? 1 : 0;
    	}
    	return cnt;
    }
};

int r,c;
int get(int x, int y){
	return x*c + y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n>>r>>c;
    DSU ds(r*c);
    int oi = 0, oj = c - 1;
    for(int i=0;i<r;++i){
      for(int j=0;j<c;++j){
        ds.unite(get(i,j),get(oi,oj));
        ++oi;
        if(oi >= r){
          oi = 0;
          --oj;
        }
      }
    }
    int cnt = ds.count();
    cout<<binExp(MB(n),cnt)<<'\n';
    return 0;
}
