#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("alimagde.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        ll N; cin >> N;
        int k = 1;
        while(k*(k+1)/2 <= N) k++;
        cout << N-(k-1) << endl;
    }
    return 0;
}
