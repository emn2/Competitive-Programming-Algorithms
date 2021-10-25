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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef ONLINE_JUDGE
    freopen("plants.in", "r", stdin); 
    #endif
    ll n; cin>>n;
    vector<ii>v(n);
    ll maximo=0;
    forc(i,0,n){
        cin>>v[i].first;
    }
    forc(i,0,n){
        cin>>v[i].second;
    }
    ll dif, dif2;
    bool flag=1;
    forc(i,0,n-1){
        dif = v[i].first-v[i+1].first;
        dif2= v[i+1].second-v[i].second;
        if(dif>0){
            if(dif2<=0){
                flag=0;
            } else {
                ll div= (dif+dif2-1)/dif2;
                maximo= max(maximo, div);
            }
        } 
    }
    forc(i,0,n){
        v[i].first+= (maximo*v[i].second);
    }
    forc(i,1,n){
        if(v[i].first< v[i-1].first){
            flag=0;
        }
    }
    if(!flag){
        cout<<"-1"<<endl;
    } else{
        cout<<maximo<<endl;
    }
    
    return 0;
}
