#include<bits/stdc++.h>
using namespace std;

template<class T>
struct BIT{
    int n;
    vector<T>bit;
    BIT(int n_=0):n(n_),bit(n+1){} //1-based
    void update(int x, T val){
        for(;x<=n;x+=(x&-x))bit[x]+=val;
    }
    T query(int x){ //query on [1,r]
        T ret=0;
        for(;x>0;x-=(x&-x))ret+=bit[x];
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n,m;
    cin>>n>>m;
  
    vector<int>penalty(n+1),sum(n+1);
    vector<pair<int,int>>v;
  
    for(int i=1;i<=n;++i){
      sum[i] = 0;
      penalty[i] = 0;
    }
  
    v.emplace_back(0,0);
    vector<pair<int,int>>ord(m);
  
    for(auto& [a,b] : ord){
      cin>>a>>b;
      sum[a]++;
      penalty[a] += b; 
      v.emplace_back(sum[a],penalty[a]);
    }
  
    sort(begin(v),end(v),[](const auto &t1, const auto &t2){
      if(t1.first != t2.first){
        return t1.first > t2.first;
      }
      return t1.second < t2.second;
    });
  
    v.erase(unique(v.begin(),v.end()),v.end());
    int len = (int)v.size();
    map<pair<int,int>,int>id;
    for(int i=0;i<len;++i){
      auto [a,b] = v[i];
      id[{a,b}] = i + 1;
    }

    BIT<int>bit(len + 1);
    sum.assign(n+1,0);
    penalty.assign(n+1,0);
    for(int i=1;i<=n;++i){
      sum[i] = 0;
      penalty[i] = 0;
      bit.update(id[{0,0}],1);
    }
    int one = id[{0,0}];
    for(auto [a,b] : ord){
      int& x = sum[a];
      int& y = penalty[a];
      bit.update(id[{x,y}],-1);
      x++;
      y += b;
      bit.update(id[{x,y}],1);

      if(a == 1)one = id[{x,y}];

      cout<<bit.query(one-1)+1<<'\n';
    }
	
    return 0;
}
