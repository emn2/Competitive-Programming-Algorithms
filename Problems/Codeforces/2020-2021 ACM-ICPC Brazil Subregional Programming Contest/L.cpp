#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<string> grid;
vector<vector<set<int> > > vis;

bool checkHorizontal(string &palavra, int linha, int coluna){
    int k = palavra.length();

    vector<int> freq(26, 0);
    vector<int> freq_palavra(26, 0);

    if(coluna + k > m) return false;

    for(int j = 0; j < k; j++){
        freq_palavra[palavra[j] - 'A']++;
        freq[grid[linha][coluna + j] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != freq_palavra[i]) return false;
    }

    return true;
}       

bool checkVertical(string &palavra, int linha, int coluna){
    int k = palavra.length();

    vector<int> freq(26, 0);
    vector<int> freq_palavra(26, 0);

    if(linha + k > n) return false;

    for(int j = 0; j < k; j++){
        freq_palavra[palavra[j] - 'A']++;
        freq[grid[linha + j][coluna] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != freq_palavra[i]) return false;
    }

    return true;
} 

bool checkDiagonalPrincipal(string &palavra, int linha, int coluna){
    int k = palavra.length();

    vector<int> freq(26, 0);
    vector<int> freq_palavra(26, 0);

    if(linha + k > n || coluna + k > m) return false;

    for(int j = 0; j < k; j++){
        freq_palavra[palavra[j] - 'A']++;
        freq[grid[linha + j][coluna + j] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != freq_palavra[i]) return false;
    }

    return true;
} 

bool checkDiagonalSecundaria(string &palavra, int linha, int coluna){
    int k = palavra.length();

    vector<int> freq(26, 0);
    vector<int> freq_palavra(26, 0);

    if(linha + k > n || coluna - k < -1) return false;

    for(int j = 0; j < k; j++){
        freq_palavra[palavra[j] - 'A']++;
        freq[grid[linha + j][coluna - j] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != freq_palavra[i]) return false;
    }

    return true;
} 

void preencherHorizontal(int linha, int coluna, int k, int ind){
    for(int i = 0; i < k; i++){
        vis[linha][coluna + i].insert(ind);
    }
}

void preencherVertical(int linha, int coluna, int k, int ind){
    for(int i = 0; i < k; i++){
        vis[linha + i][coluna].insert(ind);
    }
}

void preencherDiagonalPrincipal(int linha, int coluna, int k, int ind){
    for(int i = 0; i < k; i++){
        vis[linha + i][coluna + i].insert(ind);
    }
}

void preencherDiagonalSecundaria(int linha, int coluna, int k, int ind){
    for(int i = 0; i < k; i++){
        vis[linha + i][coluna - i].insert(ind);
    }
}

int main(){
    cin >> n >> m;

    vis.resize(n);
    grid.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        vis[i].resize(m);
    }

    int q;
    cin >> q;
    for(int k = 1; k <= q; k++){
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(checkHorizontal(s, i, j)){
                    preencherHorizontal(i, j, s.length(), k);
                }
                if(checkVertical(s, i, j)){
                    preencherVertical(i, j, s.length(), k);
                }
                if(checkDiagonalPrincipal(s, i, j)){
                    preencherDiagonalPrincipal(i, j, s.length(), k);
                }
                if(checkDiagonalSecundaria(s, i, j)){
                    preencherDiagonalSecundaria(i, j, s.length(), k);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j].size() > 1) ans++;
        }
    }

    cout << ans << '\n';
}
