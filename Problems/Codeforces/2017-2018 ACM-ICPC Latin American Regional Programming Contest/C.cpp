#include "bits/stdc++.h"
using namespace std;

bool check(map<int, int> &mp, int qnt){
    for(auto e: mp){
        if(e.second != qnt) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    
    map<int, int> mp;
    map<int, int> freq;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a]++;
    }

    for(auto e: mp) freq[e.second]++;

    int new_n = n + 1;
    if(new_n % k == 0){
        for(int i = 1; i <= k; i++){
            mp[i]++;
            if(check(mp, new_n/k)){
                cout << "+" << i << '\n';
                return 0;
            }
            mp[i]--;
        }
    }

    new_n = n - 1;
    if(new_n % k == 0){
        for(int i = 1; i <= k; i++){
            mp[i]--;
            if(check(mp, new_n/k)){
                cout << "-" << i << '\n';
                return 0;
            }
            mp[i]++;
        }
    }

    if(n % k == 0){
        int nec = n/k;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                freq[mp[i]]--, freq[mp[j]]--;

                mp[i]--, mp[j]++;

                freq[mp[i]]++, freq[mp[j]]++;

                if(freq[nec] == k){
                    cout << "-" << i << " +" << j << '\n';
                    return 0;
                }

                freq[mp[i]]--, freq[mp[j]]--;

                mp[i]++, mp[j]--;

                freq[mp[i]]++, freq[mp[j]]++;

            }
        }
    }

    cout << "*\n";

    return 0;
}
