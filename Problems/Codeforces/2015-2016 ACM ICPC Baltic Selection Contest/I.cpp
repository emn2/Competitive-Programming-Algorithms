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
    cout << fixed << setprecision(9);
    
    long double r,rzao,h;

    cin>>r>>rzao>>h;

    long double tan =h/(rzao-r);

    long double tan2 = ((-2+sqrtl(4+(4*tan*tan)))/(2*tan));

    cout<<min(rzao*tan2,h/2)<<endl;

    return 0;
}
