#include "bits/stdc++.h"
using namespace std;
int ans = 0;

void print(int *v, int n){
    for(int i = 0; i < n; i++) cout << v[i] << ' ';
    cout << '\n';
}

int partition(int *v, int l, int r){
    //ans++;
    int k = v[(l+r)/2];
    int i = l, j = r-1;
    while(i <= j){
        while(i < r && v[i] <= v[l]) i++;
        while(v[j] > v[l]) j--;
        if(i < j) swap(v[i], v[j]);
    }
    swap(v[j], v[l]);
    return j;
}


void quicksort(int *v, int l, int r){
    ans++;
    int p;
    if(r - l > 1){
        p = partition(v, l, r);
        print(v, 8);
        quicksort(v, l, p);
        print(v, 8);
        quicksort(v, p+1, r);
    }
}

int main(){
    int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    quicksort(v, 0, 8);
    cout << ans << '\n';
    return 0;
}
