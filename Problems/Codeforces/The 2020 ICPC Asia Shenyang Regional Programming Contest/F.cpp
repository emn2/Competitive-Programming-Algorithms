#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, set<int> > mp;
    vector<int> a(n), ordenado(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        ordenado[i] = a[i];
    }

    sort(ordenado.begin(), ordenado.end());

    for(int i = 0; i < n; i++){
        mp[ordenado[i]].insert(i);
    }

    int ans = 0, maximoIdx = -1;
    for(int i = 0; i < n; i++){
        auto it = mp[a[i]].begin();
        maximoIdx = max(maximoIdx, *it);
        mp[a[i]].erase(it);
        if(maximoIdx == i) ans++;
    }

    cout << ans << '\n';

    return 0;
}
