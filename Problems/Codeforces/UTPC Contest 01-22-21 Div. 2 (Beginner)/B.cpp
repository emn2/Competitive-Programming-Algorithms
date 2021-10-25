#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, x = 0, y = 0, dir = 0;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        if(s.size() == 1){
            if(s[0] == 'R') dir = (((dir+1) % 4) + 4) % 4;
            else dir = (((dir-1) % 4) + 4) % 4;
        }
        else{
            int qntd = stoi(s.substr(2));
            if(dir == 0) y += qntd;
            else if(dir == 1) x += qntd;
            else if(dir == 2) y -= qntd;
            else x -= qntd;
        }
    }
    cout << x << ' ' << y << '\n';
    return 0;   
}
