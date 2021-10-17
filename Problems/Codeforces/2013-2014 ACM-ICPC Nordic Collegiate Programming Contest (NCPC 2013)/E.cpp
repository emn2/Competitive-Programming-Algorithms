#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string original, alterada;

    cin >> original >> alterada;

    int i = 0, j = 0;
    int tam1 = original.length(), tam2 = alterada.length();

    while(i < tam1 && i < tam2 && (original[i] == alterada[i])) i++;

    while(j < tam1 && j < tam2 && (original[tam1 - j - 1] == alterada[tam2 - j - 1])) j++;

    j = tam2 - j;

    cout << max(0, max(j - i, tam2 - tam1)) << '\n';

    return 0;
}
