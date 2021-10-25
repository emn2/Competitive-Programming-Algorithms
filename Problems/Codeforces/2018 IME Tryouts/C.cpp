#include "bits/stdc++.h"
using namespace std;
const int sz = 7;

bool ok = false;
vector<int> sumRegion;
vector<vector<int> > ans, regiaoPosicao;
vector<vector<bool> > used_line, used_col, used_block, used_region;

bool check(int val, int l, int c, int b){
    if(sumRegion[regiaoPosicao[l][c]] - val < 0) return false;

    //checar linha e coluna
    if(used_line[val][l] || used_col[val][c]) return false;
    //checar regiao e bloco
    if(used_region[regiaoPosicao[l][c]][val] || used_block[val][b]) return false;

    return true;
}

int qualBloco(int x, int y){
    if(x == 0 || x == 1){
        if(y >= 3) return 2;
        else return 1;
    }
    else if(x == 2 || x == 3){
        if(y >= 3) return 4;
        else return 3;
    }
    else{
        if(y >= 3) return 6;
        else return 5;
    }
}

void solve(int x, int y){
    if(ok) return;
    else if(x == 6){
        ok = true;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else{
        for(int i = 1; i <= 6; i++){
            int b = qualBloco(x, y);
            if(check(i, x, y, b)){
                //fazer
                sumRegion[regiaoPosicao[x][y]] -= i;
                ans[x][y] = i;
                used_region[regiaoPosicao[x][y]][i] = true; 
                used_col[i][y] = used_line[i][x] = used_block[i][b] = true;

                if(y == 5) solve(x+1, 0);
                else solve(x, y+1);

                //desfazer
                sumRegion[regiaoPosicao[x][y]] += i;
                ans[x][y] = 0;
                used_region[regiaoPosicao[x][y]][i] = false; 
                used_col[i][y] = used_line[i][x] = used_block[i][b] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ans.resize(sz);
    used_col.resize(sz);
    used_line.resize(sz);
    used_block.resize(sz);
    sumRegion.resize(n+1);
    used_region.resize(n+1);
    regiaoPosicao.resize(sz);

    for(int i = 0; i <= n; i++)
        used_region[i].assign(sz, false);

    for(int i = 0; i <= 6; i++){
        ans[i].assign(sz, 0);
        regiaoPosicao[i].resize(sz);
        used_col[i].assign(sz, false);
        used_line[i].assign(sz, false);
        used_block[i].assign(sz, false);
    }

    for(int i = 1; i <= n; i++) cin >> sumRegion[i];

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            cin >> regiaoPosicao[i][j];

    solve(0, 0);

    return 0;
}
