#include "bits/stdc++.h"
using namespace std;

int binSearch(vector<int>& v, int l, int r, int target){
    if(r >= l){
        int mid = l + (r - 1) / 2;
        if(v[mid] == target) return mid;
        if(v[mid] > target)
            return binSearch(v, l, mid-1, target);
        else
            return binSearch(v, mid+1, r, target);
    }
    return -1;
}

int main(){
    int n, x, pos;
    vector<int> v;
    cin >> n >> x;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    pos = binSearch(v, 0, n-1, x);
    if((pos == -1)
        cout << "Não encontrado\n";
    else
        cout << "Numero encontrado no indice: " << pos << '\n';
    
    return 0;
}
