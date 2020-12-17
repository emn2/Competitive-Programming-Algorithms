#include "bits/stdc++.h"
using namespace std;

//Manter um intervalo [x, y], tal que s[x...y] é prefixo
//da string s e y é o maior possível

//Sabemos que s[0...(y-x)] == s[x...y], usaremos para calcular
// x+1, x+2, ..., y

//Em cada posição i, checamos o valor de z[i-x]. Se i + z[i-x] < y,
//então z[i] = z[i-x]. Entretanto, se i + z[i-x] >= y, s[0...(y-i)] = s[i...y]
//e para determinar z[i] teremos que comparar as substrings caractere
//por caractere, começando de y-i+1 até y+1.

vector<int> buildZ(string s) { 
    int n = s.size();
    int x = 0, y = 0; //intervalo

    vector<int> z(n, 0); //Z-array

    for(int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i-x], (y-i+1)));
        while((z[i] + i) < n && (s[z[i]] == s[z[i]+i])) {
            x = i; 
            y = z[i] + i; 
            z[i]++;
        }
    }
    return z;
}

int main(){
    vector<int> z = buildZ("ACBACDACBACBACDA");
    for(auto e: z)
        cout << e << ' ';
    return 0;
}
