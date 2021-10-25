#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define endl '\n'

const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    ll h, w;
    cin >> h >> w;

    if(h < 2 || w < 2){
        cout << 0 << endl;

        return 0;
    }else{

        if(w%2 == 0){
            ll qtt = (w-1) + (w/2)*(h-2);
            cout << qtt << endl;

            for(int r = h-1 ; r > 1 ; r--){
                for(int c = w-1 ; c > 0 ; c -= 2){
                    cout << r << " " << c << endl;
                }
            }

            for(int i = w-1 ; i > 0 ; i--){
                cout << 1 << " " << i << endl;
            }
        }else{
            ll qtt = (h/2) + (w-2) + ((w-1)/2)*(h-2);
            cout << qtt << endl;

            for(int i = 1 ; i < h ; i += 2){
                cout << i << " " << w-1 << endl;
            }
            
            for(int r = h-1 ; r > 1 ; r--){
                for(int c = w-2 ; c > 0 ; c -= 2){
                    cout << r << " " << c << endl;
                }
            }

            for(int i = w-2 ; i > 0 ; i--){
                cout << 1 << " " << i << endl;
            }
        }
    }

    return 0;
}
