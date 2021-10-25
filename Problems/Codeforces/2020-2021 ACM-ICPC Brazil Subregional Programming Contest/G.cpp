#include "bits/stdc++.h"
using namespace std;

int solve(vector<int>& v, int pos, int total, int qnt){
    if(pos == v.size() || qnt == v.size()) return total;
    int not_choose = total;
    int choose = solve(v, pos+1, total + v[pos], qnt + 1);
    return max(choose, not_choose);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << solve(v, 0, 100, 0) << '\n';
    return 0;
}
