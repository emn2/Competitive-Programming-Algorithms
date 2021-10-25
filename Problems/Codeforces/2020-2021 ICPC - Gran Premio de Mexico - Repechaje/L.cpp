#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        set<int> ans;

        //primeiro numero
        while(x%2 == 0){
            ans.insert(2);
            x /= 2;
        }

        for(int i = 3; i*i <= x; i+=2){
            while(x%i==0){
                ans.insert(i);
                x /= i;
            }
        }

        if(x > 1) ans.insert(x);    //is prime

        //segundo numero
        while(y%2 == 0){
            ans.insert(2);
            y /= 2;
        }

        for(int i = 3; i*i <= y; i+=2){
            while(y%i==0){
                ans.insert(i);
                y /= i;
            }
        }

        if(y > 1) ans.insert(y);    //is prime

        cout << ans.size() << '\n';
    }

    return 0;
}
