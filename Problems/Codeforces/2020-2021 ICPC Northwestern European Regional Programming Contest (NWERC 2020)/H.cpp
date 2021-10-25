#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> ans;
    for(int i = 0, j = n-1; i <= j; i++, j--){
        ans.push_back(v[i]);
        if(i != j) ans.push_back(v[j]);
    }
    reverse(ans.begin(), ans.end());
    for(auto e: ans) cout << e << ' ';

    return 0;
}
