#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, begin = 0, end = 0, cnt = 0;
    bool r1 = true, r2 = true;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        dq.push_back(a);
    }

    while((r1 || r2) && dq.size() != 0){
        if(dq.front() >= begin){
            begin = dq.front();
            dq.pop_front();
            cnt++;
        }
        else
            r1 = false;    
        if(dq.back() >= end && dq.size() != 0){
            end = dq.back();
            dq.pop_back();
            cnt++;
        }
        else
            r2 = false;
    }

    cout << cnt << '\n';

    return 0;
}
