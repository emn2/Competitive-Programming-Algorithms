#include "bits/stdc++.h"
using namespace std;

int main(){
    int cnt1 = 0, qntd1 = 0, cnt2 = 0, qntd2 = 0;
  
    string s, palavra;
    getline(cin, s);
    set<string> words;
    stringstream ss(s);
    while(ss >> palavra)
        words.insert(palavra);

    string ans1, ans2;
    getline(cin, ans1);
    stringstream ans1s(ans1);
    while(ans1s >> palavra){
        qntd1++;
        if(words.count(palavra)) cnt1++;
    }
  
    getline(cin, ans2);
    stringstream ans2s(ans2);
    while(ans2s >> palavra){
        qntd2++;
        if(words.count(palavra)) cnt2++;
    }
  
    if((cnt1/(double)qntd1) < (cnt2/(double)qntd2))
        cout << "NUMBER ONE IS THE HUMAN\n";
    else 
        cout << "NUMBER TWO IS THE HUMAN\n";
    return 0;
}
