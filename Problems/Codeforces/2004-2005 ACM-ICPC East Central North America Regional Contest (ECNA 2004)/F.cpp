#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;

    string s = "ABCDE";
    vector<string> resp;
    do{
        resp.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    while(cin >> n && n != 0){
        cin.ignore();
        int aux = 0;
        vector<pair<int, string> > val;
        vector<string> ans(n);
        for(string &a: ans) cin >> a;
        for(auto a: resp){
            aux = 0;
            for(auto b: ans){
                //checar se o par (letra1, letra2) está na mesma
                //ordem tanto na palavra 1 quanto na palavra 2
                for(char letra1 = 'A'; letra1 <= 'E'; letra1++){
                    for(char letra2 = letra1 + 1; letra2 <= 'E'; letra2++){
                        char primeiro, segundo;
                        for(int i = 0; i < 5; i++){
                            if(a[i] == letra1){
                                primeiro = letra1;
                                segundo = letra2;
                                break;
                            }
                            else if(a[i] == letra2){
                                primeiro = letra2;
                                segundo = letra1;
                                break;
                            }
                        }
                        for(int i = 0; i < 5; i++){
                            if(b[i] == segundo){
                                aux++;
                                break;
                            }
                            else if(b[i] == primeiro) break;
                        }
                    }
                }
            }
            val.push_back(make_pair(aux, a));
        }
        sort(val.begin(), val.end());
        cout << val[0].second << " is the median ranking with value " << val[0].first << ".\n";
    }

    return 0;
}

