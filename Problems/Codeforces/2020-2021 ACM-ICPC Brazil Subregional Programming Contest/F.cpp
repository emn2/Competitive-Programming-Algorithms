#include "bits/stdc++.h"
using namespace std;
//left = 1 && right = 2

int main(){
    int plGames = 0, prGames = 0, curServer = 1, pl = 0, pr = 0;
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'S'){
            if(curServer == 1) pl++;
            else pr++;
        }
        else if(s[i] == 'R'){
            if(curServer == 1) {
                pr++;
                curServer = 2;
            }
            else{
                pl++;
                curServer = 1;
            }
        }
        else if(s[i] == 'Q'){
            if(plGames == 2){
                printf("2 (winner) - %d\n", prGames);
            }
            else if(prGames == 2){
                printf("%d - 2 (winner)\n", plGames);
            }
            else if(curServer == 1){
                printf("%d (%d*) - %d (%d)\n", plGames, pl, prGames, pr);
            }
            else{
                printf("%d (%d) - %d (%d*)\n", plGames, pl, prGames, pr);
            }
        }
        if((pl >= 5 && (pl-pr) >= 2) || (pl == 10)){
            plGames++;
            pl = pr = 0;
            curServer = 1;
        }
        else if((pr >= 5 && (pr-pl) >= 2) || (pr == 10)){
            prGames++;
            pl = pr = 0;
            curServer = 2;
        }
    }
    return 0;
}
