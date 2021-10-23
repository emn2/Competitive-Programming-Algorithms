#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0; 
    for(int i = 1; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0) sum += i;
    }
    cout << sum << '\n';
}
