#include <bits/stdc++.h>

using namespace std;

#define int long long

bool f(int i, int j) {
    return i > j;
}

vector < int > arr(1000005);


int32_t main(){
	ios::sync_with_stdio(0),cin.tie(0);
    
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int silver = 0;
        if(n > 0) {
            sort(arr.begin(), arr.begin() + n, f);
            silver = arr[0];
        }
        int aux = 0;
        for(int i = k; i < n;i++) {
            aux += arr[i];
        }

        cout << max(silver, aux) << endl;
    }


    return 0;
}
