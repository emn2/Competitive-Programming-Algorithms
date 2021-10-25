#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef tuple<ll, ll, ll> tll;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    if(str.size() < 3){
        cout << "boring..." << endl;
        return 0;
    }

    for(int i = 0 ; i < str.size()-2 ; i++){
        if(str[i] == 'A' && str[i+1] == 'C' && str[i+2] == 'M'){
            cout << "Fun!" << endl;
            return 0;
        }
    }

    cout << "boring..." << endl;

    return 0;
}
