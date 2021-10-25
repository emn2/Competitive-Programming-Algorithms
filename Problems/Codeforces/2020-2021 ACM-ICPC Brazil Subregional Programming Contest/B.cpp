#include "bits/stdc++.h"
using namespace std;
//0 - horizontal
//1 - vertical

int main(){
    int i, j, n, arr[11][11];
    cin >> n;
    for(int i = 0; i < 11; i++)
        for(int j = 0; j < 11; j++)
            arr[i][j] = 0;
    
    for(int i = 0; i < n; i++){
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        if(r > 10 || c > 10 || r < 1 || c < 1){
            cout << "N\n";
            return 0;
        }
        if(d == 0){
            for(j = c; j <= 10 && l > 0; j++, l--){
                if(j == 10 && l > 1){
                    cout << "N\n";
                    return 0;
                }
                if(arr[r][j] == 0){
                    arr[r][j] = 1;
                }
                else{
                    cout << "N\n";
                    return 0;
                }
            }
        }
        else{
            for(j = r; j <= 10 && l > 0; j++, l--){
                if(j == 10 && l > 1){
                    cout << "N\n";
                    return 0;
                }
                if(arr[j][c] == 0){
                    arr[j][c] = 1;
                }
                else{
                    cout << "N\n";
                    return 0;
                }
            }
        }
    }
    cout << "Y\n";

    return 0;
}
