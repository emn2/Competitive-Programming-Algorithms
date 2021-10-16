#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 1e3, maxx = 1e5;
int pd[maxn+5][maxx+5] = {}, n, x;
vector<int> h, s;
 
int main(){
    scanf("%d %d", &n, &x);
 
    h.resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);
 
    int maj = 0, ans = 0;
    for(int i=0; i<n; i++){
        for(int w=maj; w>=0; w--){
            pd[i+1][w] = max(pd[i+1][w], pd[i][w]);
            
            if(w+h[i] <= x){
                maj = max(maj, w+h[i]);
                pd[i+1][w+h[i]] = max(pd[i][w] + s[i], pd[i+1][w+h[i]]);
                ans = max(ans, pd[i+1][w+h[i]]);
            }
        }
    }
 
    printf("%d\n", ans);
    return 0;
}
