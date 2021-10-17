#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string a, b, bReversa;
        cin >> a >> b;
        
        bReversa = b;
        reverse(bReversa.begin(), bReversa.end());

        int resp = 0, n = a.length();
        bool ans = true, taReversa = false;
       
        for(int i = 0, j = n-1; i < n && i <= j; i++, j--){
            if(taReversa){
                if(bReversa[i] == a[i] && bReversa[j] == a[j]) continue;
                else if(bReversa[i] == a[j] && bReversa[j] == a[i]){
                    resp++;
                    taReversa = !taReversa;
                }
                else{
                    ans = false;
                    break;
                }
            }
            else{
                if(b[i] == a[i] && b[j] == a[j]) continue;
                else if(b[i] == a[j] && b[j] == a[i]){
                    resp++;
                    taReversa = !taReversa;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        if(ans) cout << resp << '\n';
        else cout << "-1\n";
    }

    return 0;
}
