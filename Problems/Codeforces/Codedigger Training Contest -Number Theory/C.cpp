#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

int recursiveGCD(int a, int b){
    if(b == 0) return a;
    return recursiveGCD(b, a%b);
}

ii maximum(ii p1, ii p2){
    if(p1.first > p2.first) return p1;
    else if(p2.first > p1.first) return p2;
    else {
        if(p1.second >= p2.second) return p1;
        else return p2;
    }
}

ii max_subarray(vector <int> &v){
    int max_current = recursiveGCD(v[0], v[1]), sz = 2;
    ii max_global = {max_current, sz};
    for(int i = 2; i < v.size(); i++){
        int gcd = recursiveGCD(max_current, v[i]);
        int opt2 = recursiveGCD(v[i-1], v[i]);
        if(gcd >= opt2){
            sz++;
            max_current = gcd;
        }
        else{
            sz = 2;
            max_current = opt2;
        }
        max_global = maximum({max_current, sz}, max_global);
    }
    return max_global;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v (n);
        ii ans;

        for(int i = 0; i < n; i++)
            cin >> v[i];

        ans = max_subarray(v);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}

