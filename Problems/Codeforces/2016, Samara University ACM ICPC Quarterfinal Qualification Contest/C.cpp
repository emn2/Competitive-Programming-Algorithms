#include <bits/stdc++.h>
using namespace std;

const int lim = 1e6+10;

int res[lim];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(res,-1,sizeof(res));
    int p;cin>>p;
    for(int i=p-1;i>=0;--i){
        int x = int(1ll * i * i % p);
        res[x] = i;
    }
    for(int i=0;i<p;++i){
        cout<<res[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
