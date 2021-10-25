#include "bits/stdc++.h"
using namespace std;

typedef pair<pair<int, int>, string> iis;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cin.ignore();

    map<string, int> freq;
    map<string, int> last;

    for(int i = 1; i <= 3*n; i+=3){
        string a, b, c;
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);

        freq[a]++, freq[b]++, freq[c]++;
        last[a] = i;
        last[b] = i+1;
        last[c] = i+2;
    }

    vector<iis> ans;

    for(auto e: freq){
        ans.push_back(make_pair(make_pair(e.second, last[e.first]), e.first));
    }

    sort(ans.rbegin(), ans.rend());

    for(int i = 0; i < min(k, (int)ans.size()); i++){
        cout << ans[i].second << '\n';
    }

    return 0;
}
