#include "bits/stdc++.h"
using namespace std;

int n;
bool ans;
vector<string> grid;
vector<vector<bool> > used_line, used_col;

bool checkVisao(){
    //esquerda -> direita
    for(int i = 1; i <= n; i++){
        char esq = grid[i][0];      //restricao
        if(esq != '-'){
            int qntdEsq = 0, last = -1;
            for(int j = 1; j <= n; j++){
                if((grid[i][j] - '0') > last){
                    qntdEsq++;
                    last = (grid[i][j] - '0');
                }
            }
            if(qntdEsq != (esq - '0')) return false;
        }
    }

    //direita -> esquerda
    for(int i = 1; i <= n; i++){
        char dir = grid[i][n+1];    //restricao
        if(dir != '-'){
            int qntdDir = 0, last = -1;
            for(int j = n; j >= 1; j--){
                if((grid[i][j] - '0') > last){
                    qntdDir++;
                    last = (grid[i][j] - '0');
                }
            }
            if(qntdDir != (dir - '0')) return false;
        }
    }

    //cima -> baixo
    for(int j = 1; j <= n; j++){
        char cima = grid[0][j];     //restricao
        if(cima != '-'){    
            int qntdCima = 0, last = -1;
            for(int i = 1; i <= n; i++){
                if((grid[i][j] - '0') > last){
                    qntdCima++;
                    last = (grid[i][j] - '0');
                }
            }
            if(qntdCima != (cima - '0')) return false;
        }

    }

    //baixo -> cima
    for(int j = 1; j <= n; j++){
        char baixo = grid[n+1][j];  //restricao
        if(baixo != '-'){
            int qntdBaixo = 0, last = -1;
            for(int i = n; i >= 1; i--){
                if((grid[i][j] - '0') > last){
                    qntdBaixo++;
                    last = (grid[i][j] - '0');
                }
            }
            if(qntdBaixo != (baixo - '0')) return false;
        }
    }

    return true;
}

bool check(char val, int x, int y){
    //checar se eh repetido na linha e coluna
    if(used_line[val-'0'][x] || used_col[val-'0'][y]) return false;
    return true;
}

void solve(int x, int y){
    if(ans) return;
    else if(x == n+1){
        if(checkVisao()){
            ans = true;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cout << grid[i][j];
                }
                cout << '\n';
            }
        }
    }
    else if(grid[x][y] != '-'){
        if(y == n) solve(x+1, 1);
        else solve(x, y+1);
    }
    else{
        for(int i = 1; i <= n; i++){
            if(check((i+'0'), x, y)){
                //fazer
                grid[x][y] = (i+'0');
                used_line[i][x] = used_col[i][y] = true;
                if(y == n) solve(x+1, 1);
                else solve(x, y+1);
                //desfazer
                grid[x][y] = '-';
                used_line[i][x] = used_col[i][y] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        cin >> n;
        cin.ignore();

        grid.resize(n+2);
        used_col.resize(n+1);
        used_line.resize(n+1);

        for(int i = 0; i <= n; i++){
            used_col[i].assign(n+1, false);
            used_line[i].assign(n+1, false);
        }
        
        for(auto &a: grid) cin >> a;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] != '-'){
                    int val = grid[i][j] - '0';
                    used_col[val][j] = used_line[val][i] = true;
                }
            }
        }

        ans = false;
        solve(1, 1);
        if(!ans) cout << "no\n";
        cout << '\n';
    }   

    return 0;
}


