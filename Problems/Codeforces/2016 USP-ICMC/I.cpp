#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
#define forc(i, n) for(int i = 0; i < int(n); i++)
#define ford(i, n) for(int i = int(n-1); i >= 0; i--)

int boundXUP, boundXDOWN, boundYLEFT, boundYRIGHT;
int n, m, h, w, q;
vector<vector<bool> > colored, visited;

bool check(int f, int s){
    if(!colored[f][s] && f >= boundXUP && f < boundXDOWN && s >= boundYLEFT && s < boundYRIGHT){
        colored[f][s] = true;
        return true;
    }
    return false;
}

int complementar(int x, int y){
    int atual, qntd = 0;
    queue<ii> q;
    for(int i = x; i < x+h; i++){
        if(!colored[i][y]){
            qntd++;
            q.push(make_pair(i, y));
            colored[i][y] = true;
        }
    }
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        int f, s;
        //celula de cima
        if(cur.first != 0){
            f = cur.first-1, s = cur.second;
            if(check(f, s)){
                qntd++;
                q.push(make_pair(f, s));
            }
        }
        //celula de baixo
        if(cur.first != n-1){
            f = cur.first+1, s = cur.second;
            if(check(f, s)){
                qntd++;
                q.push(make_pair(f, s));
            }
        }
        //celula direita
        if(cur.second != m-1) {
            f = cur.first, s = cur.second+1;
            if(check(f, s)){
                qntd++;
                q.push(make_pair(f, s));
            }
        }
        //celula esquerda
        if(cur.second != 0) {
            f = cur.first, s = cur.second-1;
            if(check(f, s)){
                qntd++;
                q.push(make_pair(f, s));
            }
        }
    }
    return qntd;
}

int main(){
    scanf("%d %d %d %d %d", &n, &m, &h, &w, &q);

    colored.resize(n + 5);
    visited.resize(n + 5);
    forc(i, n) {
        colored[i].assign(m, false);
        visited[i].assign(m, false);
    }
    
    int total = n*m;
    forc(i, q){
        int x, y;
        scanf("%d %d", &x, &y);
        if(visited[x-1][y-1]){}
        else{
            boundXUP = x-1;
            boundXDOWN = x+h-1;
            boundYLEFT = y-1;
            boundYRIGHT = y+w-1;
            visited[x-1][y-1] = true;
            total -= complementar(x-1, y-1);
        }
        printf("%d\n", total);
    }

    return 0;
}
