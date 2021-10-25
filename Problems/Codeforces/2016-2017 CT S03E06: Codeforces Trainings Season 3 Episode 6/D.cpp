#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

vector<ii> posInicial;                 //White King, White Bishop, White Knight, Black King
vector<ii> posAtual;                  //White King, White Bishop, White Knight, Black King
vector<vector<bool> > attack;

bool checkmate(bool ok){
    //checar se a casa do rei preto e todas ao seu redor estão sendo atacadas
    if(!ok) return false;
    for(int i = posInicial[3].first-1; i <= posInicial[3].first+1; i++)
        for(int j = posInicial[3].second-1; j <= posInicial[3].second+1; j++)
            if(i >= 0 && i < 8 && j >= 0 && j < 8)
                if(!attack[i][j]) return false;
    return true;               
}

bool stopBishop(int i, int j){
    if(i == posAtual[2].first && j == posAtual[2].second) return true;                       //mesma casa do cavalo
    if(i == posAtual[0].first && j == posAtual[0].second) return true;                       //mesma casa do rei branco
    if(i == posAtual[3].first && j == posAtual[3].second) return true;                       //mesma casa do rei preto
    return false;   
}

bool moveBishop(int i, int j){
    if(i < 0 || i >= 8 || j < 0 || j >= 8) return false;                            //saiu do tabuleiro
    if(stopBishop(i, j)) return false;

    int k, l;
    //up-right
    for(k = i-1, l = j+1; k >= 0 && l < 8; k--, l++){
        if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;
        if(stopBishop(k, l)) break;
    }

    //up-left
    for(k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--){
        if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;
        if(stopBishop(k, l)) break;
    }

    //down-left
    for(k = i+1, l = j-1; k < 8 && l >= 0; k++, l--){
        if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;
        if(stopBishop(k, l)) break;
    }

    //down-right
    for(k = i+1, l = j+1; k < 8 && l < 8; k++, l++){
        if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;
        if(stopBishop(k, l)) break;
    }
}

bool moveKnight(int i, int j){
    if(i < 0 || i >= 8 || j < 0 || j >= 8) return false;                            //saiu do tabuleiro
    if(i == posInicial[1].first && j == posInicial[1].second) return false;                       //mesma casa do bispo
    if(i == posInicial[0].first && j == posInicial[0].second) return false;                       //mesma casa do rei branco
    if(i == posInicial[3].first && j == posInicial[3].second) return false;                       //mesma casa do rei preto

    //move knight: (i-1, j-2) e (i-1, j+2) e (i+1, j-2) e (i+1, j+2)
    for(int k = i - 1; k <= i + 1; k+=2)
        for(int l = j - 2; l <= j + 2; l += 4)
            if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;

    //move knight: (i-2, j-1) e (i-2, j+1) e (i+2, j-1) e (i+2, j+1)
    for(int k = i - 2; k <= i + 2; k+=4)
        for(int l = j - 1; l <= j + 1; l += 2)
            if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;

    return true;
}

bool moveKing(int i, int j){
    if(i < 0 || i >= 8 || j < 0 || j >= 8) return false;                                          //saiu do tabuleiro
    if(i == posInicial[1].first && j == posInicial[1].second) return false;                       //mesma casa do bispo
    if(i == posInicial[2].first && j == posInicial[2].second) return false;                       //mesma casa do cavalo
    if(abs(i - posInicial[3].first) <= 1 && abs(j - posInicial[3].second) <= 1) return false;     //nn pode se aproximar tanto do rei preto

    //casas defendidas pelo rei
    for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
            if(k == posAtual[0].first && l == posAtual[0].second) continue;
            if(k >= 0 && k < 8 && l >= 0 && l < 8)
                attack[k][l] = true;
        }
    }

    return true;
}

/*void print(int jogou, int i, int j){
    if(jogou == 0) printf("REI para %c%d\n", 'a'+i, j+1);
    else if(jogou == 1) printf("BISPO para %c%d\n", 'a'+i, j+1);
    else if(jogou == 2) printf("CAVALO para %c%d\n", 'a'+i, j+1);
    else printf("CONFIGURACAO INCIAL\n");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //if(i == posAtual[0].first && j == posAtual[0].second) cout << "R ";
            //else if(i == posAtual[1].first && j == posAtual[1].second) cout << "B ";
            //else if(i == posAtual[2].first && j == posAtual[2].second) cout << "C ";
            //else if(i == posAtual[3].first && j == posAtual[3].second) cout << "P ";
            if(attack[i][j]) cout << "X ";
            else cout << "O ";
        }
        cout << '\n';
    }
    cout << '\n';
}*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    posInicial.resize(4);
    posAtual.resize(4);
    attack.resize(8);
    bool win = false, ok = true;
    
    for(int k = 0; k < 8; k++) attack[k].assign(8, false);

    for(int i = 0; i < 4; i++){
        string s;
        getline(cin, s);
        posAtual[i].first = posInicial[i].first = s[0] - 'a';
        posAtual[i].second = posInicial[i].second = s[1] - '0' - 1;
    }

    //print(4, 0, 0);

    //for(int i = 0; i < 4; i++)
      //  printf("%d %d\n", pos[i].first, pos[i].second);

    //move white king
    for(int i = posInicial[0].first-1; i <= posInicial[0].first+1; i++){
        for(int j = posInicial[0].second-1; j <= posInicial[0].second+1; j++){
            if(i == posInicial[0].first && j == posInicial[0].second) continue;
            for(int k = 0; k < 8; k++) attack[k].assign(8, false);
            posAtual[0].first = i, posAtual[0].second = j;
            ok = moveKing(i, j);
            moveKnight(posInicial[2].first, posInicial[2].second);
            moveBishop(posInicial[1].first, posInicial[1].second);
            win = checkmate(ok);
            //if(ok) print(0, i, j);
            if(win){
                printf("K%c%d\n", 'a'+i, j+1);
                return 0;
            }
            posAtual[0].first = posInicial[0].first, posAtual[0].second = posInicial[0].second;
        }
    }

    //move knight: (i-2, j-1) e (i-2, j+1) e (i+2, j-1) e (i+2, j+1)
    for(int i = posInicial[2].first - 2; i <= posInicial[2].first + 2; i+=4){
        for(int j = posInicial[2].second - 1; j <= posInicial[2].second + 1; j += 2){
            for(int k = 0; k < 8; k++) attack[k].assign(8, false);
            posAtual[2].first = i, posAtual[2].second = j;
            ok = moveKnight(i, j);
            moveKing(posInicial[0].first, posInicial[0].second);
            moveBishop(posInicial[1].first, posInicial[1].second);
            win = checkmate(ok);
            //if(ok) print(2, i, j);
            if(win){
                printf("N%c%d\n", 'a'+i, j+1);
                return 0;
            }
            posAtual[2].first = posInicial[2].first, posAtual[2].second = posInicial[2].second;
        }
    }

    //move knight: (i-1, j-2) e (i-1, j+2) e (i+1, j-2) e (i+1, j+2)
    for(int i = posInicial[2].first - 1; i <= posInicial[2].first + 1; i+=2){
        for(int j = posInicial[2].second - 2; j <= posInicial[2].second + 2; j += 4){
            for(int k = 0; k < 8; k++) attack[k].assign(8, false);
            posAtual[2].first = i, posAtual[2].second = j;
            ok = moveKnight(i, j);
            moveKing(posInicial[0].first, posInicial[0].second);
            moveBishop(posInicial[1].first, posInicial[1].second);
            win = checkmate(ok);
            //if(ok) print(2, i, j);
            if(win){
                printf("N%c%d\n", 'a'+i, j+1);
                return 0;
            }
            posAtual[2].first = posInicial[2].first, posAtual[2].second = posInicial[2].second;
        }
    }

    int i, j;
    //move bishop up-right
    for(i = posInicial[1].first-1, j = posInicial[1].second+1; i >= 0 && j < 8; i--, j++){
        if(i == posInicial[0].first && j == posInicial[0].second) break;                    //raio-X no rei
        if(i == posInicial[2].first && j == posInicial[2].second) break;                    //raio-X no cavalo
        posAtual[1].first = i, posAtual[1].second = j;
        for(int k = 0; k < 8; k++) attack[k].assign(8, false);
        moveKnight(posInicial[2].first, posInicial[2].second);
        moveKing(posInicial[0].first, posInicial[0].second);
        ok = moveBishop(i, j);
        win = checkmate(ok);
        //if(ok) print(1, i, j);
        if(win){
            printf("B%c%d\n", 'a'+i, j+1);
            return 0;
        }
        posAtual[1].first = posInicial[1].first, posAtual[1].second = posInicial[1].second;
    }

    //move bishop up-left
    for(i = posInicial[1].first-1, j = posInicial[1].second-1; i >= 0 && j >= 0; i--, j--){
        if(i == posInicial[0].first && j == posInicial[0].second) break;                    //raio-X no rei
        if(i == posInicial[2].first && j == posInicial[2].second) break;                    //raio-X no cavalo
        for(int k = 0; k < 8; k++) attack[k].assign(8, false);
        posAtual[1].first = i, posAtual[1].second = j;
        moveKnight(posInicial[2].first, posInicial[2].second);
        moveKing(posInicial[0].first, posInicial[0].second);
        ok = moveBishop(i, j);
        win = checkmate(ok);
        //if(ok) print(1, i, j);
        if(win){
            printf("B%c%d\n", 'a'+i, j+1);
            return 0;
        }
        posAtual[1].first = posInicial[1].first, posAtual[1].second = posInicial[1].second;
    }

    //move bishop down-left
    for(i = posInicial[1].first+1, j = posInicial[1].second-1; i < 8 && j >= 0; i++, j--){
        if(i == posInicial[0].first && j == posInicial[0].second) break;                    //raio-X no rei
        if(i == posInicial[2].first && j == posInicial[2].second) break;                    //raio-X no cavalo
        for(int k = 0; k < 8; k++) attack[k].assign(8, false);
        posAtual[1].first = i, posAtual[1].second = j;
        moveKnight(posInicial[2].first, posInicial[2].second);
        moveKing(posInicial[0].first, posInicial[0].second);
        ok = moveBishop(i, j);
        win = checkmate(ok);
        //if(ok) print(1, i, j);
        if(win){
            printf("B%c%d\n", 'a'+i, j+1);
            return 0;
        }
        posAtual[1].first = posInicial[1].first, posAtual[1].second = posInicial[1].second;
    }

    //move bishop down-right
    for(i = posInicial[1].first+1, j = posInicial[1].second+1; i < 8 && j < 8; i++, j++){
        if(i == posInicial[0].first && j == posInicial[0].second) break;                    //raio-X no rei
        if(i == posInicial[2].first && j == posInicial[2].second) break;                    //raio-X no cavalo
        for(int k = 0; k < 8; k++) attack[k].assign(8, false);
        posAtual[1].first = i, posAtual[1].second = j;
        moveKnight(posInicial[2].first, posInicial[2].second);
        moveKing(posInicial[0].first, posInicial[0].second);
        ok = moveBishop(i, j);
        win = checkmate(ok);
        //if(ok) print(1, i, j);
        if(win){
            printf("B%c%d\n", 'a'+i, j+1);
            return 0;
        }
        posAtual[1].first = posInicial[1].first, posAtual[1].second = posInicial[1].second;
    }

    cout << "impossible\n";

    return 0;
}
