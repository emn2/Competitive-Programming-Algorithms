#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool notPrime[1000000];

void crivo(){
    for(int i=2; i<1000000; i++){
        if(notPrime[i])continue;
        primes.push_back(i);
        for(int j = i+i; j<1000000; j+=i){
            notPrime[j] = true;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
  
    crivo();

    long long n;
    cin >> n;
    bool cont = true;
    vector<int> divs;
    while(cont){
        if(divs.size() >= 3)break;
        bool pula = false;
        for(int i=0; i<primes.size(); i++){
            if(!(n%primes[i])){
                n /= primes[i];
                divs.push_back(primes[i]);
                pula = true;
                break;
            }
        }
        if(!pula){
            cont = false;
        }
    }
    if(n != 1 ){
        if(divs.size() == 2){
            if(divs[0] != divs[1]){
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
        return 0;
    }
    if(divs.size() != 3){
        cout << "NO\n";
        return 0;
    }
    if(divs[0] != divs[1] && divs[1] != divs[2] && divs[2] != divs[0]){
        cout << "YES\n";
        return 0;
    }else{
        cout << "NO\n";
        return 0;
    }
}
