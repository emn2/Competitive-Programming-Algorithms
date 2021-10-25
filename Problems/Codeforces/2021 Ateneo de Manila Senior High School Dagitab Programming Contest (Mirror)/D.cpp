#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, sum1 = 0, sum2 = 0, target = 0;
    cin >> n;

    target = (n+1)*n/2;
    target /= 2;
    string linha;
    for(int i = n; i > 0; i--){
        if(sum1 + i <= target){
            sum1 += i;
            linha+='A';
        }
        else{
            sum2 += i;
            linha+='B';
        }
    }

    reverse(linha.begin(),linha.end());

    cout << sum2 - sum1 << '\n';
    cout << linha << '\n';
    
    return 0;
}
//1 2 3 4 5 6 7 8 9 10

//10 9 8 7 6 5 4 3 2 1


//B A A B A A B A A B
// Se n é par, entao sobra 1.
// Se n é impar, então sobra 0.
// 55 - 10 = 45
// 45 - 9 = 36
// 36 - 8 = 28
// 27

