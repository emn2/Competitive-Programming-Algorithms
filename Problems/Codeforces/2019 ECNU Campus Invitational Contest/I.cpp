#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 505;
const ll INF = 1e8 + 5;

int n;
ll mat[N][N], dist[N][N];

void check(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] != -1){
                if(dist[i][j] < mat[i][j]){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void floyd(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
            if(i == j) dist[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                if(mat[i][j] > 0){
                    cout << "NO\n";
                    return;
                }
                else mat[i][j] = 0;
            }
            else{
                if(mat[i][j] >= 0 && mat[j][i] >= 0 && (mat[i][j] != mat[j][i])){
                    cout << "NO\n";
                    return;
                }
                else if(mat[i][j] >= 0 && mat[j][i] == -1){
                    mat[j][i] = mat[i][j];
                    dist[i][j] = dist[j][i] = mat[i][j];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == -1) dist[i][j] = INF;
            else dist[i][j] = mat[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    check();
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        floyd();
    }

    return 0;
}
