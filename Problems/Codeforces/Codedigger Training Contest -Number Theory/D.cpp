#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 100;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int pot[MAXN];
    pot[0] = 1;
    for(int i = 1; i < MAXN; i++) 
        pot[i] = (pot[i-1]*2)%MOD;

    int t;
    cin >> t;
    while(t--){
        int n, qntd2 = 0, maiorElemento = 0;
        cin >> n;
        bool pode = true;
        vector<int> v(n);
        map<int, int> freq;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            freq[v[i]]++;
            if(freq[v[i]] == 2) qntd2++;
            if(freq[v[i]] == 3) pode = false;
            if(v[i] > maiorElemento) maiorElemento = v[i];
        }

        if(freq[maiorElemento] >= 2) pode = false;

        if(!pode) cout << "0\n";
        else{
            int ocupados = qntd2*2;
            int vagos = n - ocupados - 1; //possiveis posicoes do pico

            cout << pot[vagos] << '\n';
        }
        freq.clear();
    }

    return 0;
}
