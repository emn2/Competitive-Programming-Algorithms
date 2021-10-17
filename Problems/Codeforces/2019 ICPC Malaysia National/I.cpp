#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> v(3);
    for(int i=0; i<3; i++) cin >> v[i];
    
    
    int a, b;
    for(int i=0; i<3; i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j] == '='){
                a = i;
                b = j+1;
            }
        }
    }
    
    char c = '\0';
    while(b < v[a].size()){
        if(v[a][b] != '.'){
            c = v[a][b];
            break;
        }
        b++;
    }
    
    if(c != '\0') cout << c << '\n';
    else cout << "You shall pass!!!\n";
    
    return 0;
}
