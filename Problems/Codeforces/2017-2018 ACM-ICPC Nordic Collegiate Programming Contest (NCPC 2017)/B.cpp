#include "bits/stdc++.h"
using namespace std;

typedef pair<pair<double, double>, string> dds;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    double mini = 1e9;

    vector<dds> run(n);

    for(int i = 0; i < n; i++){
        cin >> run[i].second >> run[i].first.second >> run[i].first.first;
    }

    vector<int> ans(4);
    vector<int> resto;

    sort(run.begin(), run.end());

    for(int i = 0; i < n; i++){
        int cnt = 1;
        double sum = run[i].first.second;
        resto.push_back(i);
        for(int j = 0; j < n; j++){
            if(i != j){
                sum += run[j].first.first;
                cnt++;
                resto.push_back(j);
            }
            if(cnt == 4) break;
        }
        if(sum < mini){
            for(int k = 0; k < 4; k++) ans[k] = resto[k];
            mini = sum;
        }
        resto.clear();
    }

    cout << mini << '\n';
    for(auto e: ans){
        cout << run[e].second << '\n';
    }

    return 0;
}
