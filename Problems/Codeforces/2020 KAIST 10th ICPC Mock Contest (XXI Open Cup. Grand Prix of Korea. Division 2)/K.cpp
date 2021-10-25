#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<ii, int> > pontos(n+1);

    for(int i = 1; i <= n; i++){
        cin >> pontos[i].first.first >> pontos[i].first.second;
        pontos[i].second = i;
    }
    
    sort(pontos.begin(), pontos.end());

    cout << 2*n-1 << '\n';

    for(int i = 1; i <= n; i++)
        cout << pontos[i].second << ' ';
        
    for(int i = n-1; i >= 1; i--)
        cout << pontos[i].second << ' ';

    return 0;
}
