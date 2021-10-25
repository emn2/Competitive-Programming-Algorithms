#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll inf = 3e9;

struct node{
    ll pos, pop, idx;
} no;

bool cmp(const node& a, const node& b){
    return (a.pos < b.pos);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> par(n+1);
    vector<node> aux, city(n+1), left(n+1), right(n+1);   //distancia, pop, indice
    for(int i = 1; i <= n; i++) {
        cin >> city[i].pos >> city[i].pop;
        city[i].idx = i;
    }
    if(n > 1)
        sort(city.begin()+1, city.end(), cmp);

    city[0].pos = -inf, city[0].pop = inf, city[0].idx = -1;
    aux.push_back(city[0]);
    for(int i = 1; i <= n; i++){
        while(aux.back().pop <= city[i].pop) aux.pop_back();
        left[i] = aux.back();
        aux.push_back(city[i]);
    }
    aux.clear();

    node extra;
    extra.pos = inf, extra.pop = inf, extra.idx = -1;
    aux.push_back(extra);
    for(int i = n; i >= 1; i--){
        while(aux.back().pop <= city[i].pop) aux.pop_back();
        right[i] = aux.back();
        aux.push_back(city[i]);
    }

    for(int i = 1; i <= n; i++){
        if(abs(city[i].pos-left[i].pos) == abs(right[i].pos-city[i].pos)){
            if(left[i].pop > right[i].pop) par[city[i].idx] = left[i].idx;
            else par[city[i].idx] = right[i].idx;
        }
        else if(abs(city[i].pos-left[i].pos) < abs(right[i].pos - city[i].pos)) par[city[i].idx] = left[i].idx;
        else par[city[i].idx] = right[i].idx;
    }
    
    for(int i = 1; i <= n; i++) cout << par[i] << ' ';
    
    return 0;
}
