#include "bits/stdc++.h"
using namespace std;
#define x first
#define y second
typedef pair<double, double> dd;
const int MAXN = 15;

int n;
int color[MAXN] = {};
int graph[MAXN][MAXN] = {};

double dist(dd &a, dd &b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool isSafe(){
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
 
bool graphColoring(int m, int i){
    if (i == n) {
        if(isSafe()) {
            return true;
        }
        return false;
    }
 
    for (int j = 1; j <= m; j++) {
        color[i] = j;
        if (graphColoring(m, i + 1))
            return true;
 
        color[i] = 0;
    }
 
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int idx = 1;
    while(cin >> n && n != 0){
        memset(graph, 0, sizeof(graph));
        int m = 1, ans = 0;
        vector<dd> towers(n);
        for(int i = 0; i < n; i++){
            cin >> towers[i].x >> towers[i].y;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(dist(towers[i], towers[j]) <= 20.0){
                    graph[i][j] = graph[j][i] = 1;
                }
            }
        }
        bool foi = false;
        while(!foi){
            for(int i = 0; i < MAXN; i++) color[i] = 0;
            if(!graphColoring(m, 0)) m++;
            else{
                foi = true;
                printf("The towers in case %d can be covered in %d frequencies.\n", idx++, m);
            }
        }
    }

    return 0;
}
