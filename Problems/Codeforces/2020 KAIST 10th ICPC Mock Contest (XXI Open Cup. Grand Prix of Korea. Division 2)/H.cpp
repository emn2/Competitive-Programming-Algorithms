#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void solve(vector<set<int> >& subsets, vector<int>& actual, int idx){
    set<int> prov;
    for(auto e: actual) prov.insert(e);
    subsets.push_back(prov);
    prov.clear();
    for (int i = idx; i <= 6; i++){ 
        actual.push_back(i);
        solve(subsets, actual, i + 1); 
        actual.pop_back(); 
    } 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, ans = 0, aux = 0, sum = 0;
    cin >> n >> k;
    vector<set<int> > subsets;
    vector<int> actual;
    vector<int> price(7);
    vector<int> c(n);

    for(int i = 1; i <= 6; i++) cin >> price[i];
    for(int &a: c) cin >> a;

    solve(subsets, actual, 1);

    for(int i = 0; i < 64; i++){
        for(auto e: c){
            if(subsets[i].count(e)){
                if(price[e]+sum <= k){
                    aux++;
                    sum += price[e];
                }
                else break;
            }
        }
        ans = max(ans, aux);
        aux = sum = 0;
    }

    cout << ans << '\n';

    return 0;
}
