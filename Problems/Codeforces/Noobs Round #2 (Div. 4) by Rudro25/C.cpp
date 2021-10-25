#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, qntd = 0, i, j, sz;
        cin >> n >> k;
        vector<int> v;
        for(i = 0; i < n; i++){
            int a; cin >> a;
            if(a >= k) qntd++;
            else v.push_back(a);
        }
        sort(v.begin(), v.end());
        sz = v.size() - 1;
        for(i = 0, j = sz; j > i; j--){
            do{
                if(v[i] + v[j] >= k) qntd++;
            }while((v[i++] + v[j] < k) && (j>i));
        }
        cout << qntd << '\n';
        v.clear();
    }

    return 0;
}
