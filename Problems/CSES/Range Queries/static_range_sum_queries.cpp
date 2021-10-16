#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    vector<ll> sum(n+1, 0);
    for(int i = 1; i <= n; i++){
        ll a;
        scanf("%lld", &a);
        sum[i] += sum[i-1] + a;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", sum[b] - sum[a-1]);
    }
    return 0;
}
