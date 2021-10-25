#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    bool ok = true;
    deque<ii> dq;
    vector<ii> v;
    for(int i = 0; i < n/2; i++){
        int a, b;
        cin >> a >> b;
        if(b > a) swap(a, b);
        v.push_back(make_pair(a, b));
    }
    sort(v.rbegin(), v.rend());
    dq.push_back(v[0]);
    for(int i = 1; i < n/2 && ok; i++){
        int l = dq.front().first, r = dq.back().second;
        if(l > r){
            if(v[i].first > l) ok = false;
            else{
                swap(v[i].first, v[i].second);
                dq.push_front(v[i]);
            }
        }
        else{
            if(v[i].first > r) ok = false;
            else{
                dq.push_back(v[i]);
            }
        }
    }

    if(!ok) cout << "-1\n";
    else{
        while(!dq.empty()){
            cout << dq.front().first << ' ' << dq.front().second << ' ';
            dq.pop_front();
        }
    }

    return 0;
}
