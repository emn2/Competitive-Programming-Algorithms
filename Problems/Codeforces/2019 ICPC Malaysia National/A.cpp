#include "bits/stdc++.h"
using namespace std;

void solve(vector<string>& grid, int qntd, int n){
    vector<string> v = grid;
    for(int k = 0; k < qntd; k++){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v.size(); j++){
                grid[j][n-1-i] = v[i][j];
            }
        }
        v = grid;
    }
}

int main(){
    int n, left = 0, right = 0, qntd;
    string s;
    cin >> n >> s;
    vector<string> grid(n);

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    string simb = "^>v<";

    for(auto e: s)
        if(e == 'L') left++;
        else right++;

    qntd = (((right - left) % 4) + 4) % 4;

    solve(grid, qntd, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '^'){
                printf("%c", simb[(4+qntd)%4]);
            }
            else if(grid[i][j] == '>'){
                printf("%c", simb[(5+qntd)%4]);
            }
            else if(grid[i][j] == 'v'){
                printf("%c", simb[(6+qntd)%4]);
            }
            else if(grid[i][j] == '<'){
                printf("%c", simb[(7+qntd)%4]);
            }
            else
                printf("%c", grid[i][j]);
        }
        cout << '\n';
    }

    return 0;
}
