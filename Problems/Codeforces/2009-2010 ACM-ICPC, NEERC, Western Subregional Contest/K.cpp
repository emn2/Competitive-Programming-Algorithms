#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout.precision(9);
    cout << fixed;
  
    freopen("kids.in", "r", stdin);
    freopen("kids.out", "w", stdout);

    ld n,m;

    cin>>n>>m;

    ld raz = (n-1)/n;
    ld prob = 1;
    for(int i=0;i<m;i++){

      prob = prob*raz;
    }

    cout<<n*(1-prob)<<endl;



    return 0;
}
