#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define max(a, b) ((a > b) ? a : b)

//0 -> left and 1 -> right

//Se estiver indo para a esquerda, o tempo eh
//o max entre ans e p, e se estiver indo para a direita
//eh o max entre ans e L-p, que eh a diff

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll L, n, ans = 0;
    cin >> L >> n;

    for(int i = 0; i < n; i++){
        ll p, d;
        cin >> p >> d;
        if(d) ans = max(ans, L-p);
        else ans = max(ans, p);
    }
    cout << ans << '\n';
    return 0;
}
