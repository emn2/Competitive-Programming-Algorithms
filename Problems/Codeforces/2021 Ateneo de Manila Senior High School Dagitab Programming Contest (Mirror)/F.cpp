#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    vector<string> arr(n+1);
    if(k>n/2){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        string a;
        cin >> a;
        arr[(i+k)%(n+1)] = a;
    }
    for(int i = 0; i <=n; i++) {
        if(arr[i]!="") cout << arr[i] << ' ';
    }
    return 0;
}

