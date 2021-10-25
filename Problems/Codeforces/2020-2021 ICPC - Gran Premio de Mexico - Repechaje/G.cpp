#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define max(a, b) ((a > b) ? a : b)
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)

//0 -> left and 1 -> right

//Se estiver indo para a esquerda, o tempo eh
//o max entre ans e p, e se estiver indo para a direita
//eh o max entre ans e L-p, que eh a diff

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll L, n, ans = 0;
    cin >> L >> n;

    forc(i, 0, n){
        ll p, d;
        cin >> p >> d;
        if(d) ans = max(ans, L-p);
        else ans = max(ans, p);
    }
    cout << ans << '\n';
    return 0;
}
