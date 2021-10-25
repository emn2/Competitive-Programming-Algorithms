#include "bits/stdc++.h"
using namespace std;
#define ll long long 

const ll INF = 1e18 + 5;
 
ll beginning;
int n, cnt = 0;
map<ll, int> mp;
 
bool check(ll mod){
    map<ll, int> agora;
    ll aux = beginning % mod;
    for(int i = cnt; i < n; i++, aux = (aux * 2) % mod){
        agora[aux]++;
        if(agora[aux] > mp[aux]) return false;
    }
    return true;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
 
    set<ll> pot;
    vector<ll> v(n);
    set<ll> retirar;
 
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
        pot.insert(v[i]);
    }
 
    ll missing = 1;
    while(1){
        if(!pot.count(missing)) {
            beginning = missing;
            break;
        }
        else{
            cnt++;
            mp[missing]--;
            retirar.insert(missing);
            missing *= 2;
        }
    }
 
    ll l = v[n-1] + 1, r = missing - 1;

    if(v[0] == 0){
        cout << r+1 << '\n';
        return 0;
    }

    set<ll> candidates;
 
    for(int i = 0; i < n; i++){
        if(retirar.count(v[i])){
            retirar.erase(v[i]);
        }
        else {
            if(r + 1 - v[i] >= l) candidates.insert(r + 1 - v[i]);
            ll aux = v[i];
            while(aux <= v[n-1]){
                aux *= 2;
                retirar.insert(aux);
            }
        }
    }

    for(auto e: candidates){
        if(check(e)){
            cout << e << '\n';
            return 0;
        }
    }

    while(1){
        if(check(l)){
            cout << l << '\n';
            return 0;
        }
        l++;
    }

    return 0;
}
