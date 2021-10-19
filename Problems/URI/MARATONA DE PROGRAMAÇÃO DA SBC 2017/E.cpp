#include "bits/stdc++.h"
using namespace std;

struct node {
    string nota;
    bitset<12> escala;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<node> mp(12);

    mp[0].nota = "do"; mp[1].nota = "do#";
    mp[2].nota = "re"; mp[3].nota = "re#";
    mp[4].nota = "mi"; mp[5].nota = "fa";
    mp[6].nota = "fa#"; mp[7].nota = "sol";
    mp[8].nota = "sol#"; mp[9].nota = "la";
    mp[10].nota = "la#"; mp[11].nota = "si";

    bitset<12> padrao("101011010101");

    mp[0].escala = padrao;

    for(int i = 1; i < 12; i++){
        bitset<12> agora;
        int j = 0, qnt = 12;

        while(qnt--){
            agora[j] = padrao[(i+j)%12];
            j++;
        }
        mp[i].escala = agora;
    }

    int n;
    cin >> n;

    bitset<12> tocadas("000000000000");
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a = (a-1)%12;
        tocadas[(11 - a)] = 1;
    }

    for(int i = 0; i < 12; i++){
        if((tocadas & mp[i].escala) == tocadas){
            cout << mp[i].nota << '\n';
            return 0;
        }
    }

    cout << "desafinado\n";
}
