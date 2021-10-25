#include "bits/stdc++.h"
using namespace std;
#define IS_ON(pos, bitmask) (1 << pos) & bitmask

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    map<string, char> mp;

    string s, m;
    cin >> m >> s;

    int bin = 2*k + 1, sz = s.size();

    //criar o "dicionario"
    for(int mask = (1 << bin) - 1, i = 0; mask >= 0; i++, mask--){
        string x = "";
        for(int j = bin-1; j >= 0; j--){
            if((1 << j) & mask) x += '1';
            else x += '0';
        }
        mp[x] = m[i];
    }

    while(q--){
        string aux = s + s + s;
        string atual = "";
        for(int i = sz; i < 2*sz; i++){
            string x = aux.substr(i-k, k) + aux[i] + aux.substr(i+1, k);
            atual += mp[x];
        }
        s = atual;
    }

    cout << s << '\n';

    return 0;
}
