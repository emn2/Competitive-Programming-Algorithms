#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int nt;
    cin >> nt;
    
    for(int t=1; t<=nt; t++){
        
        int qtn;
        cin >> qtn;
        vector<int> v(qtn);
        for(int &u: v) cin >> u;
        sort(v.begin(), v.end());
        
        
        long long moment = 0;
        int ans = 0;
        
        for(int u: v){
            if(moment <= u){
                moment += u;
                ans++;
            }
        }
        
        cout << "Case #" << t << ": " << ans << '\n';
    }
    
    return 0;
}
