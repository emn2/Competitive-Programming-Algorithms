#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main(){
    int c, p, s;
    cin >> c >> p >> s;
    cin.ignore();
    map<string, int> cand;
    map<string, int> disc;
    set<string> w;
    for(int i = 0; i < c; i++){ //candidates
        string pes;
        getline(cin, pes);
        w.insert(pes);
        cand[pes] = 0;
    }
    for(int i = 0; i < p; i++){ //problems
        int pnt, aux;
        string mat, dd;
        getline(cin, mat);
        for(int j = 0; j < mat.size(); j++){
            if(mat[j] == ' '){
                aux = j;
                pnt = stoll(mat.substr(j+1));
                break;
            }
        }
        dd = mat.substr(0, aux);
        disc[dd] = pnt;
    }
    for(int i = 0; i < s; i++){
        string sub, ps, m, g;
        int aux1 = 0, aux2 = 0, cnt = 0;
        getline(cin, sub);
        for(int j = 0; j < sub.size(); j++){
            if(sub[j] == ' ' && aux1 == 0){
                aux1 = j;
                cnt = 1;
                ps = sub.substr(0, j);
            }
            else if(sub[j] == ' ' && cnt == 1){
                aux2 = j;
                m = sub.substr(aux1 + 1, aux2 - aux1 - 1);
                break;
            }
        }
        g = sub.substr(aux2 + 1);
        if(g == "AC"){
            cand[ps] += disc[m];
        }
    }

    for(auto it = cand.begin(); it != cand.end(); it++){
        if(w.count(it->first))
            cout << it->first << " " << it->second << endl;
    }

    return 0;
}
