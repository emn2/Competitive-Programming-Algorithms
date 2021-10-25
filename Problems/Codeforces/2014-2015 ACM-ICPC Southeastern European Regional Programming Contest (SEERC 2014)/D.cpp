#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("d.in", "r", stdin);

    int x, y;
    cin >> y >> x;
    
    //duas linhas de size X e duas colunas de size Y, cada uma compartilha um bloco

    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        bool ans = false;
        
        if((x-2) % k == 0 && y % k == 0) ans = true;
        else if((x-2) % k == 0 && (x-1) % k == 0 && y % k == 0 && (y-1) % k == 0) ans = true;
        else if((x-2) % k == 0 && x % k == 0 && (y-1) % k == 0) ans = true;
        else if((x-1) % k == 0 && (x-2) % k == 0 && y % k == 0 && (y-1) % k == 0) ans = true;
        else if((x-1) % k == 0 && (y-2) % k == 0 && y % k == 0) ans = true;
        else if((x-1) % k == 0 && (y-1) % k == 0) ans = true;
        else if((x-1) % k == 0 && x % k == 0 && (y-1) % k == 0 && (y-2) % k == 0) ans = true;
        else if((x-1) % k == 0 && (x-2) % k == 0 && (y-1) % k == 0 && y % k == 0) ans = true;
        else if(x % k == 0 && (y-2) % k == 0) ans = true;


        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
