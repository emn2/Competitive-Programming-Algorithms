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
    cout << fixed << setprecision(12);
    int n;
    cin>>n;

    while(n--){
        long double a,b;
        cin>>a>>b;
        long double ans = (1/a) - (1/(b+1));
        cout<<ans<<endl;
    }

    return 0;
}
