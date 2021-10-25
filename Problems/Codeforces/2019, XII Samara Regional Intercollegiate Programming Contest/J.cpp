#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<ll> sum(n);
    vector<ll> doisMenores(n), ans(n, 0);
    for(int i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        sum[i] = a + b + c;
        doisMenores[i] = sum[i] - max(a, max(b, c)) + 2;
        if(sum[i] >= doisMenores[i]) ans[i]--;
    }

    sort(doisMenores.begin(), doisMenores.end());   //soma minima para superar o adversario x

    for(int i = 0; i < n; i++){
        ll pos = upper_bound(doisMenores.begin(), doisMenores.end(), sum[i]) - doisMenores.begin();
        ans[i] += pos;
    }

    for(auto e: ans) cout << e << ' ';

    return 0;
}
