#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const int tam = 1e6 + 5;

char grid[1250][1250];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("figure.in", "r", stdin);
    freopen("figure.out", "w", stdout);

    int t; cin >> t;
    while(t--){

        int h, w, n;
        cin >> h >> w >> n;

        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                grid[i][j] = '.';
            }
        } 

        int qtd = 0;

        for(int i = 1;i < h - 1;i++){
            for(int j = (i % 2 == 0) ? 2 : 1;j < w - 1;j+=2){
                grid[i][j] = '#';
                qtd++;
                if(qtd >= n) {
                    i = h;
                    break;
                }
            }
        }

        if(qtd < n){
            cout<<"Impossible"<<endl<<endl;
        }
        else{
            for(int i = 0;i < h;i++){
                for(int j = 0;j < w;j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
        }

    }

    return 0;
}
