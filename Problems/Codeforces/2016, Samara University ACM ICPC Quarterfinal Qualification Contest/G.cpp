#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<tuple<int,int,int>>orc(n);
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        orc[i] = {a,b,i};
    }
    int m;cin>>m;
    vector<tuple<int,int,int>>axe(m);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        axe[i] = {a,b,i};
    }
    sort(rbegin(orc),rend(orc));
    sort(rbegin(axe),rend(axe));
    vector<int>ans(n);
    set<pair<int,int>>q;
    bool ok = true;
    for(int l=0,r=0;l<n;++l){
        while(r < m && get<0>(orc[l]) <= get<0>(axe[r])){
            q.insert({get<1>(axe[r]),get<2>(axe[r])});
            ++r;
        }
        auto id = q.lower_bound({get<1>(orc[l]),-1});
        ans[get<2>(orc[l])] = (id != q.end() ? (*id).second + 1 : -1);
        if(id != q.end())q.erase(id);
        ok &= id != q.end();
    }
    if(ok){
        for(int x : ans){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
    
    return 0;
}
