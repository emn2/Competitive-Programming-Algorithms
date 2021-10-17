#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, e, ans = 0;
    cin >> n >> k >> e;

    int sum = 0;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int missing = (sum - k + e - 1)/e;

    cout << max(n, missing) << '\n';

    return 0;
}
