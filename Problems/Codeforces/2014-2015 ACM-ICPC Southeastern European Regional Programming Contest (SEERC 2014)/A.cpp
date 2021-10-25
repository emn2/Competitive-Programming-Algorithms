#include "bits/stdc++.h"
#define inf 1000001 //DEPENDS ON THE PROBLEM
#define ll long long
#define endl '\n'

using namespace std;

bool has_root(ll a) {
  ll up = ceil(sqrt(a));
  ll bot = sqrt(a);
  return up == bot;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("a.in", "r", stdin);
  
  ll n;
  cin >> n;
  set <pair<ll, ll>> sete;
  vector <ll> in;
  for(ll i = 0; i < n; i++) {
    ll aux;
    cin >> aux;
    in.push_back(aux);
    sete.insert({aux, i});
  }

  ll cont = 0;
  while(1) {
    pair<ll, ll> p = (*sete.begin());
    sete.erase(p);
    if(p.first >= 0) break;


    ll pos_l = (p.second-1) >= 0 ? p.second - 1 : n-1;
    ll pos_r = (p.second+1) < n ? p.second + 1 : 0;
  
    pair<ll, ll> vl = {in[pos_l], pos_l}, vr = {in[pos_r], pos_r};
    sete.erase(vl);
    sete.erase(vr);

    p.first = p.first*-1;
    in[p.second] = p.first;
    vl.first -= p.first;
    in[vl.second] = vl.first;
    vr.first -= p.first;
    in[vr.second] = vr.first;

    sete.insert(p);
    sete.insert(vl);
    sete.insert(vr);

    cont++;
  }
  cout << cont << endl;
}
