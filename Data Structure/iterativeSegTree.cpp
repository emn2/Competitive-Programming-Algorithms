#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;
int n;
int tree[2*N];

//build the tree from bottom to top
void build(){
    for(int i = n-1; i > 0; i--) 
        tree[i] = tree[2*i] + tree[2*i + 1];
}

void modify(int p, int val){
    for(tree[p += n] = val; p > 1; p /= 2)
        tree[p/2] = tree[p] + tree[p^1];        //(p^1) -> rc ou lc
}

//General idea is the following.
//If l, the left interval border, is odd (which is equivalent to l&1)
//then l is the right child of its parent. 
//Then our interval includes node l but doesn't include it's parent. 
//So we add t[l] and move to the right of l's parent by setting l = (l + 1) / 2. 
//If l is even, it is the left child, and the interval includes its parent as well 
//(unless the right border interferes), so we just move to it by setting l = l / 2. 
//Similar argumentation is applied to the right border. We stop once borders meet.

int query(int l, int r){
    int ans = 0;
    for(l += n, r += n; l < r; l /= 2, r /= 2){
        if(l&1) ans += tree[l++];
        if(r&1) ans += tree[--r];
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &tree[n + i]);
    build();
    return 0;
}


//If we don't have a perfect bin tree (pow of 2)
//then we need to modify our functions a bit

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) tree[l++] += value;
    if (r&1) tree[--r] += value;
  }
}

int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += tree[p];
  return res;
}
