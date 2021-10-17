#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int j = 1; j <= t; j++){
        int n, s, maior = INT32_MIN;
        cin >> n >> s;
        for(int i = 0; i < n; i++){
            int f, t;
            cin >> f >> t;
            if(t > s)
                maior = max(maior, (f - t + s));
            else
                maior = max(maior, f);
        }
        printf("Case #%d: %d\n", j, maior);
    }

    return 0;
}
