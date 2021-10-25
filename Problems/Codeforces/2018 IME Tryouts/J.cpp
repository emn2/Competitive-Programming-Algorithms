#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6 + 5;

int tree[maxn];

void update(int pos){
    pos += 2;
    while(pos < maxn){
        tree[pos] += 1;
        pos += (pos & -pos);
    }
}

int query(int pos){
    int ans = 0;
    pos += 2;
    while(pos > 0){
        ans += tree[pos];
        pos -= (pos & -pos);
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a; 
        scanf("%d", &a);
        printf("%d\n", n - (i - query(a-1)));
        update(a);
    }

    return 0;
}
