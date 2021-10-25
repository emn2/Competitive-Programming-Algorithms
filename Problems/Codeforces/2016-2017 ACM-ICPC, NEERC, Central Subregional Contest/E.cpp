#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define endl '\n'

const ll mod = 1e9+7;

ll getrounds(ll n, ll total, ll qtt, ll add, ll k, ll big){
    ll l = 1;
    ll r = 1e8;

    while(l < r){
        ll rounds = (l+r)/2;

        ll mini = rounds*((n-1) + big);
        ll maxi = rounds*total;

        if(k < mini+qtt){
            r = rounds-1;
        }else if(k >= mini+qtt && k <= maxi+add){
            return rounds;
        }else{
            l = rounds+1;
        }
    }

    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    ll n, k;
    cin >> n >> k;
    
    ll total = 0, big = 0;
    vll vec(n);
    for(int i = 0 ; i < n ; i++){
        cin >> vec[i];
        total += vec[i];

        big = max(big, vec[i]);
    }

    ll add = 0, qtt = 0;
    for(int i = 0 ; i < n ; i++){
        if(vec[i] == big){
            qtt = i;

            if(k >= i && k <= add){
                cout << "YES" << endl;
                return 0;
            }else if(k < i || k <= big+i){
                cout << "KEK" << endl;
                return 0;
            }
            break;
        }
        add += vec[i];
    }

    ll rounds = getrounds(n, total, qtt, add, k, big);

    ll mini = rounds*((n-1) + big);
    ll maxi = rounds*total;

    if(k >= mini+qtt && k <= maxi+add){
        cout << "YES" << endl;
    }else{
        cout << "KEK" << endl;
    }

    return 0;
}
