#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int> > dist(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        for(int j = 0; j < n; j++){
            dist[i][j] = s[j]-'0';
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int ans = 0;
            for(int k = i+1; k <= j-1; k++){
                ans += dist[i][k]*dist[k][j];
            }
            if(dist[i][j] == (ans+1)%10) dist[i][j] = 1;
            else dist[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << dist[i][j];
        cout << '\n';
    }

    return 0;
}
