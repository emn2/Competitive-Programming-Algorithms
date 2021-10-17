#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, a;
    cin >> n;

    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;

    for(int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    while(pq.size() > 1){
        ll primeiro = pq.top();
        pq.pop();
        ll segundo = pq.top();
        pq.pop();

        if(primeiro == segundo){
            pq.push(2*primeiro);
        }
        else if((segundo / primeiro) % 2 == 1){
            cout << "-1\n";
            return 0;
        }
        else{   
            pq.push(2*primeiro);
            pq.push(segundo);
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

