#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef long double ld;

const ll mod = 1e9+7;
const int inf = 1e9;

int main () {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n,x;
    cin>>n>>x;

    string s;
    cin>>s;

    int m;
    cin>>m;

    string moves;
    cin>>moves;
    int tam = moves.length(),pos = x-1;
    string ans;
    ans +=s[pos];

    for(int i=0;i<tam;i++){
        if(moves[i]=='R'){
            pos++;
            ans+=s[pos];
        }
        else if(moves[i] =='L'){
             pos--;
            ans+=s[pos];
        }
    }
    cout<<ans<<endl;
    return 0;
}
