#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> tree;

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

void update(int val, int pos){
    while(pos <= n){
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main(){
    cin >> n;
    tree.assign(n+1, 0);

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        update(a, i);
    }

    for(int i = 1; i <= n; i++)
        cout << i << ' ' << tree[i] << '\n';

    return 0;
}
