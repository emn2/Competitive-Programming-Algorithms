#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &e: v) cin >> e;
    v.push_back(-1);
    stack<int> s;
    for(int i = 0; i < v.size(); i++){
        while(!s.empty() && v[i] < v[s.top()]){
            int top = s.top();
            s.pop();
            if(s.empty()){
                int l = min(i, v[top]);
                ans = max(ans, l);
            }
            else {
                int l = min(v[top], i-1-s.top());
                ans = max(ans, l);
            }
        }
        s.push(i);
    }
    cout << ans << '\n';
    return 0;
}
