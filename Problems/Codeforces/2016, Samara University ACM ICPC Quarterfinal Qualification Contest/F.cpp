#include "bits/stdc++.h"
using namespace std;
#define x first
#define y second
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

bool ganhou(iii &a, iii &b){
    int v1 = 0, v2 = 0;
    if(a.x.x > b.x.x) v1++;
    else v2++;
    
    if(a.x.y > b.x.y) v1++;
    else v2++;

    if(a.y > b.y) v1++;
    else v2++;

    if(v1 > v2) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<iii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].x.x >> a[i].x.y >> a[i].y;

    int pior = 0;
    for(int i = 1; i < n; i++){
        if(ganhou(a[pior], a[i])) pior = i;
    }

    bool ganhaDeAlguem = false;
    for(int i = 0; i < n; i++){
        if(i != pior && ganhou(a[pior], a[i])){
            ganhaDeAlguem = true;
            break;
        }
    }

    if(ganhaDeAlguem) cout << 0 << '\n';
    else{
        cout << 1 << '\n';
        cout << pior + 1 << '\n';
    }

    return 0;
}
