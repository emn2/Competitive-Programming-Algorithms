#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());

    int ans = k;
    for(int i = k; i < n; i++){
        if(a[i] == a[i-1]) ans++;
        else break;
    }

    cout << ans << '\n';
}
