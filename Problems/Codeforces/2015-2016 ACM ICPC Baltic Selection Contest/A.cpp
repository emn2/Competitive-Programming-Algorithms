#include "bits/stdc++.h"
using namespace std;

int main(){
    string a, b, resp;
    cin >> a >> b;

    for(int i = a.length() - 1; i >= 0; i--){
        int d1 = a[i]-'0', d2 = b[i]-'0';
        resp += (abs(d1 - d2)+'0');
    }
    reverse(resp.begin(), resp.end());
    int j = 0;
    while(true){
        if(resp[j] != '0') break;
        j++;
    }
    resp = resp.substr(j, resp.length() - j);
    if(resp == "") cout << "0";
    else cout << resp;

    return 0;
}
