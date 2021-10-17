#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("bulls.in", "r", stdin);
    freopen("bulls.out", "w", stdout);

    string a, b;
    cin >> a >> b;

    int bull = 0, cow = 0;
    map<char, int> mpb;

    for(int i = 0; i < 4; i++){
        if(a[i] == b[i]) bull++;
        else{
            mpb[b[i]]++;
        }
    }

    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]){
            if(mpb[a[i]] > 0){
                cow++;
                mpb[a[i]]--;
            }
        }
    }

    cout << bull << ' ' << cow << '\n';

    return 0;
}
