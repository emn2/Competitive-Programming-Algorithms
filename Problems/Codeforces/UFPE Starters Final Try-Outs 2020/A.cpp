#include "bits/stdc++.h"
using namespace std;

#define int long long

const int LIM = 5e5 + 5;
const int prime = 1e9 + 7;
 
int hash_left[LIM]; 
int hash_right[LIM]; 

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string aux;
    cin >> aux;

    string s = "$" + aux;

    unsigned long long MOD = 1;
    for(int i = 0; i < m; i++){
        MOD = MOD*prime;
    }

    for(int i = 1; i <= n; i++)
        hash_left[i] = prime*hash_left[i-1] + (s[i] - 'a' + 1);
    
    for(int i = n; i > 0; i--)
        hash_right[i] = prime*hash_right[i+1] + (s[i] - 'a' + 1);

    for(int i = m; i <= n; i++){
        if(hash_left[i] - MOD*hash_left[i-m] == hash_right[i-m+1] - MOD*hash_right[i+1]){
            cout << "Accept\n";
            return 0;
        }
    }
    

    cout << "Reject\n";
}
