#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt = 0;
    for(auto e: s){
        cnt += (e - '0');
    }

    cout << cnt % 3 << '\n';
}
